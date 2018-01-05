import java.util.Scanner;

public class DijkstrasAlgorithm {
	
	static int findIndexOfVertex(String[] vertex, int n, String vertexPos) {
		int position = 0;
		for (int i = 0; i < n; i++) {
			if (vertex[i].equals(vertexPos))
				position = i;
		}
		return position;
	}
	
	public static void main(String[] args) {
		// getting the input.
		Scanner s = new Scanner(System.in);
		System.out.println("Enter number of vertices :");
		int n = s.nextInt();
		
		System.out.println("Enter all the vertex :");
		String vertex[] = new String[n];
		for (int i = 0; i < n; i++) {
			vertex[i] = s.next();
		}
		
		System.out.println("Enter the matrix : ");
		int matrix[][] = new int[n][n];
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				matrix[i][j] = s.nextInt();
			}
		}
		
		System.out.println("Enter start vertex : ");
		String startVertex = s.next();

		//Formation.
		int position = DijkstrasAlgorithm.findIndexOfVertex(vertex,n,startVertex);
		int dj = -1;
		
		String vertex1[] = new String[n-1];
		int matrix1[][] = new int[n][n-1];
		for (int i = 0; i < n-1; i++) {
			if (i == position)
				dj += 2;
			else
				dj++;
			vertex1[i] = vertex[dj];
			matrix1[0][i] = matrix[position][dj];
		}
		int di = 0;
		for (int i = 1; i < n; i++) {
			dj = 0;
			if (di == position)
				di++;
			for (int j = 0; j < n - 1; j++) {
				if (dj == position)
					dj++;
				matrix1[i][j] = matrix[di][dj];
				dj++;
			}
			di++;
		}
		
		// Initialize table.
		int table[][] = new int[n][n - 1];
		String backpath[][] = new String[n][n - 1];
		int min = 9999, minVertex = 0;
		for (int i = 0; i < n - 1; i++) {
			table[0][i] = matrix1[0][i];
			backpath[0][i] = startVertex;
			if (min > table[0][i]) {
				min = table[0][i];
				minVertex = i;
			}
		}

		// Fill table.
		int temp;
		int min1 = 9999, minVertex1 = 0;
		for (int i = 1; i < n; i++) {
			for (int j = 0; j < n - 1; j++) {
				if (table[i - 1][j] != -2) { 
					if (j == minVertex) {
						table[i][j] = -2;
						backpath[i][j] = "-2";
					} else {
						temp = min + matrix1[minVertex+1][j];
						table[i][j] = table[i - 1][j] < temp ? table[i - 1][j] : temp;
						backpath[i][j] = table[i - 1][j] < temp ? backpath[i - 1][j] : vertex1[minVertex];
					}
					if (min1 > table[i][j] && table[i][j] > 0) {
						min1 = table[i][j];
						minVertex1 = j;
					}
				} else {
					table[i][j] = -2;
					backpath[i][j] = "-2";
				}
			}
			min = min1;
			min1 = 9999;
			minVertex = minVertex1;
			minVertex1 = 0;
		}

		// Printing the table.
		System.out.println("Dynamic Table is : ");
		for (int j = 0; j < n - 1; j++) {
			System.out.print(vertex1[j] + "\t");
		}
		System.out.println("");
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n - 1; j++) {
				System.out.print("( " + table[i][j] + " , " + backpath[i][j] + " )\t\t");
			}
			System.out.println("");
		}

		// backtracking.
		int b = 0, k = 0;
		int j = 0;
		String path[] = new String[n];
		for (int i = 0; i < n - 1; i++) {
			b = 0;
			k = 0;
			System.out.println("Path from " + startVertex + " to destination " + vertex1[i] + " is : ");
			while (table[b][i] != -2) {
				b++;
			}
			System.out.println("Total Weight : " + table[b - 1][i]);
			path[k] = vertex1[i];
			k++;
			b--;
			if(!backpath[b][i].equals(startVertex)) {
				position = DijkstrasAlgorithm.findIndexOfVertex(vertex1, n-1, backpath[b][i]);
			}
			else position = -1;
			b = position;
			while (b != -1) {
				path[k] = vertex1[b];
				k++;
				j = 0;
				while (table[j][b] != -2) {
					j++;
				}
				j--;
				if(!backpath[j][b].equals(startVertex)) {
					position = DijkstrasAlgorithm.findIndexOfVertex(vertex1, n-1, backpath[j][b]);
				}
				else position = -1;
				b = position;
			}
			path[k] = startVertex;

			// printing path
			System.out.print("Path is : ");
			for (int l = k; l >= 0; l--) {
				System.out.print(" " + path[l]);
			}
			System.out.println("");
		}

	}
}
