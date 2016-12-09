class TestLinkedList {
	public static void main(String[] args) {
		LinkedList<String> list = new LinkedList();
		list.add("this");
		list.add("is");
		list.add("my");
		list.add("own");
		list.add("LinkedList");
		list.add("implementation");

		System.out.println(list);

		list.remove("own");
		System.out.println(list);

		String found = list.find("own") ? "yes" : "no";
		System.out.println("Did you find the removed entity (own) ? " + found);

		list.resetFetchPointer();
		list.find("is");
		list.deleteNext(); // "is" will be pointed to by current pointer now, deleteNext will delete the next entity "my" from list

		System.out.println(list);
		
		list.insertAfter("a", "is");
		list.insertBefore("good", "LinkedList");

		System.out.println(list);

	}	
}


