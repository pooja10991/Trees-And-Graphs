import java.util.Iterator;
import java.util.Scanner;

public class PrimsAlgorithm {
	public int[][] getMST(int[][] matrix, int n, String[] vertex) {
		int MSTMatrix[][] = new int[n][n];
		int totalMSTWeight = 0;
		PriorityQueue pq = new PriorityQueue();
		String preed[] = new String[n];
		
		//Initializing.
		Vertex v = new Vertex();
		v.setName(vertex[0]);
		v.setWeight(0);
		pq.insert(v);
		preed[0] = "-1";
		for (int i = 1; i < n; i++) {
			Vertex v1 = new Vertex();
			v1.setName(vertex[i]);
			v1.setWeight(9999);
			pq.insert(v1);
		}
		int i = 0;
		int j = 0;
		while (pq.size()!=0) {
			//Getting the minimum value.
			Vertex v2 = pq.extractMin();
			i = getIndexFromNode(n, vertex, v2.getName());
			String preed1 = preed[i];
			if (!preed1.equals("-1"))
				j = getIndexFromNode(n, vertex, preed1);
			else
				j = 0;
			totalMSTWeight += v2.getWeight();
			MSTMatrix[i][j] = v2.getWeight();
			MSTMatrix[j][i] = v2.getWeight();
			
			//Changing the weights adjacent vertex.
			for (int k = 0; k < n; k++) {
				Vertex v3 = pq.getVertex(vertex[k]);				
				if (v3!=null && matrix[i][k] != 0 && matrix[i][k] < v3.getWeight() && pq.contains(v3)) {
					pq.decreaseKey(v3, matrix[i][k]);
					preed[k] = v2.getName();
				}
			}
		}

		System.out.println("Total Weight of MST : " + totalMSTWeight);
		return MSTMatrix;
	}

	public int getIndexFromNode(int n, String[] vertex, String node) {
		for (int i = 0; i < n; i++) {
			if (vertex[i].equals(node))
				return i;
		}
		return -1;
	}

	public static void main(String[] args) {
		// getting the input.
		Scanner s = new Scanner(System.in);
		System.out.println("Enter number of vertex.:");
		int n = s.nextInt();
		System.out.println("Enter all the vertex :");
		String vertex[] = new String[n];
		for (int i = 0; i < n; i++) {
			vertex[i] = s.next();
		}
		System.out.println("Enter the matrix (space seperated for column and new line for new row.) : ");
		int matrix[][] = new int[n][n];
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				matrix[i][j] = s.nextInt();
			}
		}
		
		//Getting MST.
		int MSTMatrix[][] = new int[n][n];
		PrimsAlgorithm pa = new PrimsAlgorithm();
		MSTMatrix = pa.getMST(matrix, n, vertex);

		// Printing MSTMatrix.
		System.out.println("MST Matrix is : ");
		System.out.print(" \t");
		for (int j = 0; j < n; j++) {
			System.out.print(vertex[j] + "\t");
		}
		System.out.println("");
		for (int i = 0; i < n; i++) {
			System.out.print(vertex[i] + "\t");
			for (int j = 0; j < n; j++) {
				System.out.print(MSTMatrix[i][j] + "\t");
			}
			System.out.println("");
		}
	}
}
