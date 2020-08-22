#include <iostream>
using namespace std;
template <class T>
class List
{
private:
	struct Node
	{
		T value;
		Node* next;
	};
	Node* head;
	int size;
public:
	List() : head(nullptr), size(0) { }
	List(const List& tmp)
	{
		Node* current = tmp.head;
		while (current != nullptr)
		{
			this->AddToTail(current->value);
			current = current->next;
		}
		size = 0;
	}
	List& operator=(const List& tmp)
	{
		if (this == &tmp)
		{
			return *this;
		}
		this->head->value = tmp.head->value;
		this->head->next = tmp.head->next;
		return *this;
	}
	
	void AddToHead(T value)
	{
		Node* newElem = new Node;
		newElem->value = value;
		newElem->next = head;
		head = newElem;
		this->size = size + 1;
	}
	void DeleteHead()
	{
		if (head == nullptr)
		{
			return;
		}
		Node* temp = head->next;
		delete head;
		if (temp == nullptr)
		{
			head = nullptr;
		}
		else
		{
			head = temp;
		}
		this->size = size - 1;
	}
	void AddToTail(T value)
	{
		Node* newElem = new Node;
		newElem->value = value;
		newElem->next = nullptr;

		if (head == nullptr)
		{
			head = newElem;
		}
		else
		{
			Node* current = head;
			while (current->next != nullptr)
			{
				current = current->next;
			}
			current->next = newElem;
		}
		this->size = size + 1;
	}
	void DeleteTail()
	{
		if (head == nullptr)
		{
			return;
		}
		if (head->next == nullptr)
		{
			delete head;
			head = nullptr;
		}
		else
		{
			Node* current = head;
			while (current->next->next != nullptr)
			{
				current = current->next;
			}
			delete current->next;
			current->next = nullptr;
		}
		this->size = size - 1;
	}
	void DeleteAll()
	{
		~List();
		this->size = 0;
	}
	bool IsEmpty() const
	{
		return head == nullptr;
	}
	
	int Search(T value)
	{
		Node* temp = head;
		for (int i = 0; i < size; i++)
		{
			if (temp->value == value)
			{
				cout << i + 1 << endl;
			}
			temp = temp->next;
		}
		return -1;
	}
	
	void Show() const
	{
		Node* current = head;
		int counter = 0;
		while (current != nullptr)
		{
			if (counter + 1 == size)
			{
				cout << current->value << "  ";
			}
			else
			{
				cout << current->value << ", ";
			}
			counter++;
			current = current->next;
		}
		cout <<"\nSize: "<< size << endl<<endl;
	}
	
	~List()
	{
		while (!IsEmpty())
		{
			DeleteHead();
		}
	}
	void InsertIndex(T value, int index)
	{
		Node* newElem = new Node;
		newElem->value = value;
		newElem->next = nullptr;
		Node* node = head;
		for (int i = 0; i < index; i++)
		{
			node = node->next;
		}
		newElem->next = node->next;
		node->next = newElem;
		this->size = size + 1;
	};
	void RemoveIndex(int index)
	{
		if (!size)
		{
			return;
		}
		if (index == 0)
		{
			Node* temp = head->next;
			delete head;
			head = temp;
			this->size = size - 1;
			return;
		}
		Node* node = head;
		for (int i = 0; i < index - 1; i++)
		{
			node = node->next;
		}
		Node* del = node->next;
		node->next = del->next;
		delete del;
		this->size = size - 1;
	}
};

int main()
{
	List<int> ls;
	ls.AddToHead(10);
	ls.AddToHead(15);
	ls.AddToHead(5);
	ls.AddToHead(20);
	ls.AddToTail(99);
	ls.Show();
	ls.InsertIndex(999,3);
	ls.Show();
	ls.RemoveIndex(2);
	ls.Show();
	ls.DeleteHead();
	ls.DeleteTail();
	ls.Show();
	ls.Search(10);

	return 0;
}