#include <iostream>
#include <string>
#include <stack>
#define SPACE 10
using namespace std;

class Node
{
private:
	string word, meaning;
	Node *left;
	Node *right;

public:
	Node(string w = "", string m = "")
	{
		this->meaning = m;
		this->word = w;
		this->left = NULL;
		this->right = NULL;
	}
	friend class BST;
};

class BST
{
private:
	Node *root;

public:
	BST()
	{
		root = NULL;
	}
	Node *getRoot()
	{
		return root;
	}
	void setRoot(Node *r)
	{
		root = r;
	}

	void insert(Node *, string, string);
	void inorderDisplay(Node *);
	void search(Node *, string);
	//void deleteWord(Node*, string);
	Node *deleteWord_rec(Node *, string);
	Node *minValueNode(Node *);
	void max_cmp(Node *);
	void updateWord(Node *, string);
	void display_desc(Node *);
	void display2D(Node *, int);
};

void BST::insert(Node *p, string key, string keyMeaning)
{
	if (key < p->word)
	{
		if (p->left != NULL)
			insert(p->left, key, keyMeaning);
		else
			p->left = new Node(key, keyMeaning);
	}
	else if (key > p->word)
	{
		if (p->right != NULL)
			insert(p->right, key, keyMeaning);
		else
			p->right = new Node(key, keyMeaning);
	}
	else
	{
		cout << "\nYou have entered duplicate keyword!" << endl;
	}
}

void BST::display2D(Node *r, int space)
{
	if (r == NULL) //base case
		return;
	space += SPACE;							//increase distance between levels
	display2D(r->right, space); //process right child first
	cout << endl;
	for (int i = SPACE; i < space; i++)
	{
		cout << " ";
	}
	cout << r->word << "\n";	 //print current node after space count
	display2D(r->left, space); //process left child first
}

void BST::inorderDisplay(Node *temp)
{
	if (temp != NULL)
	{
		inorderDisplay(temp->left);
		cout << "    " << temp->word << " :: " << temp->meaning << endl;
		inorderDisplay(temp->right);
	}
}

void BST::max_cmp(Node *itr)
{
	stack<Node *> stack1;
	static int maxCount = 0;
	while (itr != NULL || stack1.empty() == false)
	{
		while (itr != NULL)
		{
			stack1.push(itr);
			itr = itr->left;
		}
		itr = stack1.top();
		stack1.pop();
		maxCount++;
		itr = itr->right;
	}
	cout << "max comparisons :" << maxCount << endl;
}

void BST::search(Node *p, string key)
{
	Node *temp = p;
	int count = 0;
	while (p != NULL)
	{
		if (key < p->word)
		{
			count++;
			p = p->left;
		}
		else if (key > p->word)
		{
			count++;
			p = p->right;
		}
		else if (key == p->word)
		{
			count++;
			cout << "Number of comparisons required to find the keyword: " << count << endl;
			max_cmp(temp);
			return;
		}
	}
	cout << "Word not found!" << endl;
}

Node *BST::deleteWord_rec(Node *root, string key)
{
	if (root == NULL)
	{
		cout << "Given keyword is not present in dictionary" << endl;
		return root;
	}
	else if (key < root->word)
		root->left = deleteWord_rec(root->left, key);
	else if (key > root->word)
		root->right = deleteWord_rec(root->right, key);
	else //keyword found now deleting it
	{
		//case 1: No child
		if (root->left == NULL && root->right == NULL)
		{
			delete root;
			root = NULL;
			cout << "\nNode deleted having no child" << endl;
		}
		//case 2: one right child
		else if ((root->left == NULL) && (root->right != NULL))
		{
			Node *temp = root;
			root = root->right;
			delete temp;
			cout << "Node deleted having only right child" << endl;
		}
		//case 3: one left child
		else if ((root->right == NULL) && (root->left != NULL))
		{
			Node *temp = root;
			root = root->left;
			delete temp;
			cout << "Node deleted having only left child" << endl;
		}
		//case 4: 2 children
		else
		{
			Node *temp = minValueNode(root->right);
			root->word = temp->word;
			root->meaning = temp->meaning;
			root->right = deleteWord_rec(root->right, temp->word);
			cout << "Node deleted having left and right child" << endl;
		}
		return root;
	}
}

Node *BST::minValueNode(Node *node)
{
	Node *current = node;
	while (current->left != NULL)
	{
		current = current->left;
	}
	return current;
}

void BST::updateWord(Node *p, string key)
{
	while (p != NULL)
	{
		if (key < p->word)
			p = p->left;
		else if (key > p->word)
			p = p->right;
		else if (key == p->word)
		{
			cout << "\nEnter its new meaning : ";
			cin >> p->meaning;
			cout << "Keyword meaning updated successfully!" << endl;
			return;
		}
	}
	cout << "\nWord is not present in dictionary!";
}

void BST::display_desc(Node *temp)
{
	if (temp->right != NULL)
		display_desc(temp->right);
	cout << "    " << temp->word << " :: " << temp->meaning << endl;
	if (temp->left != NULL)
		display_desc(temp->left);
}

int main()
{
	int choice, n;
	string newWord, newMeaning, searchWord;
	BST t1;
	do
	{
		cout << "\n<<-----------MENU----------->>" << endl;
		cout << "0. see tree in 2D" << endl;
		cout << "1. Insert new words" << endl;
		cout << "2. Display in-order" << endl;
		cout << "3. Delete a word" << endl;
		cout << "4. No. of comparisons" << endl;
		cout << "5. Search keyword and update a its meaning" << endl;
		cout << "6. Display keywords and meaning in descending order" << endl;
		cout << "7. EXIT" << endl;
		cout << "<<-------------------------->>" << endl;
		cout << "\nEnter your choice: ";
		cin >> choice;
		switch (choice)
		{
		case 0:
			t1.display2D(t1.getRoot(), 5);
			cout << endl;
			break;
		case 1:
			cout << "Enter the number of words to insert: ";
			cin >> n;
			for (int i = 0; i < n; i++)
			{
				cout << "\nEnter the keyword to be inserted: ";
				cin >> newWord;
				cout << "Enter its meaning: ";
				cin >> newMeaning;
				if (t1.getRoot() == NULL)
				{
					Node *newNode = new Node(newWord, newMeaning);
					t1.setRoot(newNode);
				}
				else
					t1.insert(t1.getRoot(), newWord, newMeaning);
			}
			break;
		case 2:
			t1.inorderDisplay(t1.getRoot());
			break;

		case 3:
		{
			cout << "\nEnter the keyword to delete: ";
			cin >> searchWord;
			t1.deleteWord_rec(t1.getRoot(), searchWord);
			break;
		}
		case 4:
		{
			cout << "\nEnter the word to find comparisons: ";
			cin >> searchWord;
			t1.search(t1.getRoot(), searchWord);
			break;
		}
		case 5:
			cout << "\nEnter the word to search: ";
			cin >> searchWord;
			t1.updateWord(t1.getRoot(), searchWord);
			break;
		case 6:
			t1.display_desc(t1.getRoot());
			break;
		case 7:
			cout << "\nEXIT!! Good Bye!!" << endl;
			break;
		default:
			cout << "\nInvalid input!";
		}
	} while (choice != 7);

	return 0;
}
