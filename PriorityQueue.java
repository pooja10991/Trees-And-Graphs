
public class PriorityQueue {
	java.util.PriorityQueue<Vertex> pq = new java.util.PriorityQueue<Vertex>();
	
	public void insert(Vertex v) {
		pq.add(v);
	}
	
	public Vertex extractMin() {
		return (Vertex)pq.poll();
	}
	
	public int size() {
		return pq.size();
	}
	
	public void decreaseKey(Vertex v, int newKey) {
		pq.remove(v);
		v.setWeight(newKey);
		pq.add(v);
	}
	
	public boolean contains(Vertex v) {
		return pq.contains(v);
	}
	
	public Vertex getVertex(String VertexName) {
		Vertex v = new Vertex();
		for (Object v3 : pq) {
			v = (Vertex)v3;
			if(v.getName().equals(VertexName))
				break;
			else
				v = null;
		}
		return v;
	}
}
