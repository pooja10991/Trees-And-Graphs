import java.util.Comparator;

public class Vertex implements Comparable<Vertex> {
	private String name;
	private int weight;

	public String getName() {
		return name;
	}

	public void setName(String name) {
		this.name = name;
	}

	public int getWeight() {
		return weight;
	}

	public void setWeight(int weight) {
		this.weight = weight;
	}

	@Override
	public int compareTo(Vertex v1) {
		/*Integer i = this.weight;
		Integer i1 = v1.getWeight();
		return i.compareTO(i1);*/
		return this.getWeight() < v1.getWeight() ? -1
		         : this.getWeight() > v1.getWeight() ? 1
		         : 0;
	}

}
