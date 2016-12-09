import java.util.*;

class LinkedList<E> implements Iterable<E> {
	private Node<E> head;
	private Node<E> current;

	private static class Node<E> {
		private E data;
		private Node<E> next;

		public Node(E data, Node<E> next) {
			this.data = data;
			this.next = next;
		}
	}

	public LinkedList() {
		this.current = this.head = null;
	}

	public boolean isEmpty() {
		return head==null;
	}

	public boolean moreItemsAvailable() {
		return (head!=null && current!=null);
	}

	public void addFirst(E element) {
		head = new Node<E>(element, head);
		current = head;
	}

	public void add(E element) {
		if (this.isEmpty()) {
			addFirst(element);
		}
		else {
			Node<E> aNode = new Node<E>(element, null);
			Node<E> runner = head;
			while(runner.next!=null) {
				// find last element
				runner = runner.next;
			}
			runner.next = aNode;
		}
	}

	public E getNext() {
		if (current == null) {
			throw new NoSuchElementException();			
		}

		E datum = current.data;
		current = current.next;
		return datum;
	}

	public void deleteNext() {
		/* use case for this method? if the user wants to truncate the list 
		at this point he will call deleteNext recursively */

		if (current == null) {
			throw new NoSuchElementException();			
		}
		else if (current == head) {
			removeAtFirst(current.data);
		}
		else 
			current.next = current.next.next;
	}

	public boolean removeAtFirst(E element) {
		boolean deletedHead = false;
		if (head==null) {
			throw new UnsupportedOperationException();
		}
		else if (head.data == element) {
			head = head.next;
			current = head;
			deletedHead = true;
		}

		return deletedHead;
	}

	public boolean remove(E element) throws UnsupportedOperationException {
		/* will remove first occurence of element */
		Node<E> runner = head;
		boolean somethingGotDeleted = false;

		// handle deletion if required at head
		somethingGotDeleted = removeAtFirst(element);

		while(!somethingGotDeleted && runner!=null) {
			if (runner.next.data == element) {
				runner.next = runner.next.next;
				somethingGotDeleted = true;
			}
			else
				runner = runner.next;
		}

		return somethingGotDeleted;
	}

	public int removeAllOccurences(E element) {
		Node<E> runner = head;
		int deleteCount = 0;

		while(runner!=null && runner.next!=null) {
			/* check from 1st position, we'll handle if there's a 0th position deletion at the last */
			if (runner.next.data==element) {
				runner.next = runner.next.next;
				deleteCount++;
			}
			runner = runner.next;
		} 

		deleteCount+=(removeAtFirst(element)) ? 1 : 0;
		return deleteCount;
	}

	public boolean find (E element) {
		/* this will look for an element in the list, 
		if found, it will return true and also set 
		current pointer to that element to facilitate getNext*/
		Node<E> runner = head;
		while(runner!=null) {
			if(runner.data == element) {
				current = runner;
				return true;
			}
			runner = runner.next;
		}

		return false;
	}

	public void resetFetchPointer() {
		current = head;
	}

	public void clear() {
		head = null;
	}

	public void insertAfter(E newElement, E existing) {
		Node<E> runner = head;
		while(runner!=null) {
			if(runner.data==existing) {
				runner.next = new Node<E>(newElement, runner.next);
				runner = null;
			}
			else
				runner = runner.next;
		}
	}

	public void insertBefore(E newElement, E existing) {
		Node<E> runner = head;
		if (head==null) return; 

		if (head.data == existing) {
			head = new Node<E>(newElement, head);
			return;
		}

		while(runner!=null && runner.next!=null) {
			if(runner.next.data == existing) {
				runner.next = new Node<E>(newElement, runner.next);
				runner = null;
			}
			else
				runner = runner.next;
		}
	}

	public LinkedList reverse() {
		LinkedList list = new LinkedList();
		Node<E> runner = head;
		while(runner!=null) {
			list.addFirst(runner.data);			
			runner = runner.next;
		}
		return list;
	}

	public Iterator<E> iterator() {
		return new LinkedListIterator();
	}

	private class LinkedListIterator implements Iterator<E> {
		private Node<E> nextNode;

		public LinkedListIterator() {
			nextNode = head;
		}

		public boolean hasNext() {
			return nextNode!=null;
		}

		public E next() {
			if(!hasNext()) throw new NoSuchElementException();
			E data = nextNode.data;
			nextNode = nextNode.next;
			return data;
		}

		public void remove() {
			throw new UnsupportedOperationException();
		}
	}

	public String toString() {
		Iterator<E> itr = iterator();
		StringBuilder sb = new StringBuilder();
		while(itr.hasNext()) {
			sb.append(itr.next());
			sb.append(" ");
		}
		return sb.toString();
	}
}