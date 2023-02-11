
#include <iostream>
#include <stack>
#include <queue>
#define SPACE 10
using namespace std;

class TreeNode {
private:
    int data;
    TreeNode* left;
    TreeNode* right;
    friend class BinaryTree;

public:
    TreeNode(){
        this->left = NULL;
        this->right = NULL;
        this->data = -1;
    }
    TreeNode(int data){
        this->data = data;
        left = NULL;
        right = NULL;
    }
};

class BinaryTree {
private:
    TreeNode* root;
    int recently_added;
public:
    BinaryTree(){
        root = NULL;
        recently_added = 0;
    }

    void add_node_itr(int data){
        TreeNode* newNode = new TreeNode(data);

        if (root == NULL){
            root = newNode;
            cout << "Node has been added at the root!" << endl;
        }
        else {
            TreeNode* temp = root;
            char pos;
            while (temp != NULL){
                cout << "Enter the position of new node W.R.T " << temp->data << " (l/r): ";
                cin >> pos;

                if (temp->left == NULL && pos == 'l'){
                    temp->left = newNode;
                    cout << "Node has been added to the left W.R.T. "<< temp->data << endl;
                    break;
                }
                else if (temp->right == NULL && pos == 'r'){
                    temp->right = newNode;
                    cout << "Node has been added to the right W.R.T. " << temp->data << endl;
                    break;
                }
                else if (pos == 'l')
                	temp = temp->left;
                else if (pos == 'r')
                	temp = temp->right;
            }
        }
    }

    void print2D(TreeNode *r, int space)
	{
		if(r==NULL) //base case
			return;
		space+=SPACE; //increase distance between levels
		print2D(r->right,space);   //process right child first
		cout << endl;
		for(int i=SPACE;i<space;i++)
		{
			cout << " ";
		}
		cout << r->data << "\n";  //print current node after space count
		print2D(r->left,space);    //process left child first
	}

    void add_input(int data){
        this->recently_added = data;
        TreeNode* newNode = new TreeNode(data);
        add_node_rec(newNode, this->root);
        cout << "Node has been added using recursion!" << endl;
    }
    void add_node_rec(TreeNode* newNode, TreeNode* root){
        if (root){
            char pos;
            cout << "Enter the position of new node W.R.T " << root->data << " (l/r): ";
            cin >> pos;
            if (root->right == NULL && pos == 'r'){
                root->right = newNode;
                return;
            }
            else if (root->left == NULL && pos == 'l'){
                root->left = newNode;
                return;
            }
            else if (pos == 'l' )
            	add_node_rec(newNode, root->left);
            else if (pos == 'r')
            	add_node_rec(newNode, root->right);
        }
    }

    //TODO: rec traversal
    void inorder_rec(TreeNode* root){
        if (root){
            inorder_rec(root->left);
            cout << root->data << " ";
            inorder_rec(root->right);
        }
    }

    void postorder_rec(TreeNode* root){
        if (root){
            postorder_rec(root->left);
            postorder_rec(root->right);
            cout << root->data << " ";
        }
    }

    void preorder_rec(TreeNode* root){
        if (root){
            cout << root->data << " ";
            preorder_rec(root->left);
            preorder_rec(root->right);
        }
    }

    //TODO: in-order
    void inorder_itr(){
        TreeNode* itr = root;
        stack <TreeNode*> stack1;
        while (itr != NULL || stack1.empty() == false){
            while (itr != NULL){
                stack1.push(itr);
                itr = itr->left;
            }
            itr = stack1.top();
            stack1.pop();

            cout << itr->data << " ";
            itr = itr->right;
        }
    }

    //TODO: post-order
    void postorder_itr(){
        TreeNode* itr = root;
        stack <TreeNode*> stack1;
        if (root == NULL) return;

        do {
            while (itr){
                if (itr->right){
                    stack1.push(itr->right);
                }
                stack1.push(itr);
                itr = itr->left;
            }
            itr = stack1.top();
            stack1.pop();

            if (itr->right && !stack1.empty() && stack1.top() == itr->right){
                stack1.pop();
                stack1.push(itr);
                itr = itr->right;
            }
            else {
                cout << itr->data << " ";
                itr = NULL;
            }
        } while (stack1.empty() == false);
    }

    //TODO: pre-order
    void preorder_itr(){
        TreeNode* itr = root;
        stack <TreeNode*> stack1;
        stack1.push(itr);

        while(stack1.empty() == false){
            itr = stack1.top();
            cout << itr->data << " ";
            stack1.pop();

            if (itr->right)
            	stack1.push(itr->right);
            if (itr->left)
            	stack1.push(itr->left);
        }
    }

    int height_itr(){
        int height_tree = 0;
        TreeNode* itr = root;

        if (itr == NULL) return 0;
        queue<TreeNode*> queue1;

        queue1.push(itr);
        int num_of_nodes_left;

        while (true){
            num_of_nodes_left = queue1.size();
            if (num_of_nodes_left == 0)
            	return height_tree-1;

            height_tree++;

            while (num_of_nodes_left > 0){
                itr = queue1.front();
                queue1.pop();
                if (itr->left)
                	queue1.push(itr->left);
                if (itr->right)
                	queue1.push(itr->right);
                num_of_nodes_left--;
            }
        }
    }

    //TODO: Heigh of tree
    int height_rec(TreeNode* itr){
        if (itr == NULL) return -1; //logic: height is 1 less than number of max nodes
        else {
            int left_height = height_rec(itr->left);
            int right_height = height_rec(itr->right);

            if (left_height > right_height)
            	return left_height+1;
            else
            	return right_height+1;
        }
    }

    BinaryTree operator = (BinaryTree b){
        BinaryTree copied;
        copied.setRoot(copyNodes(b.getRoot()));
        cout << "\nTree copied successfully!!!" << endl;
        return copied;
    }

    TreeNode* copyNodes(TreeNode* root_original){
        TreeNode* temp;
        if (root_original){
            temp = new TreeNode();
            temp->left = copyNodes(root_original->left);
            temp->right = copyNodes(root_original->right);
            temp->data = root_original->data;
            return temp;
        }
        return NULL;
    }

    BinaryTree operator = (const BinaryTree &b){
        BinaryTree copied;

        if (b.root == NULL)
        	return copied;
        queue<TreeNode*> queue1;
        TreeNode* itr = b.root;
        queue1.push(itr);

        while (!queue1.empty()){
            itr = queue1.front();
            queue1.pop();

            TreeNode* newNode = new TreeNode();
            newNode = itr;

            if (itr->left)
            	queue1.push(itr->left);
            if (itr->right)
            	queue1.push(itr->right);
        }
        return copied;
    }

    void swap_rec(TreeNode* itr){
        if (itr == NULL)
        	return;

        swap_rec(itr->left);
        swap_rec(itr->right);

        TreeNode* temp;
        temp = itr->left;
        itr->left = itr->right;
        itr->right = temp;
    }

    void swap_itr(){
        TreeNode* itr = root;
        if (itr == NULL)
        	return;

        queue<TreeNode*> queue1;
        queue1.push(itr);

        while (!queue1.empty()){
            itr = queue1.front();
            queue1.pop();

            TreeNode* temp = itr->left;
            itr->left = itr->right;
            itr->right = temp;

            if (itr->left)
            	queue1.push(itr->left);
            if (itr->right)
            	queue1.push(itr->right);
        }
    }

    int leafNodes(TreeNode* r)
    {
    	if(r==NULL)
    	{
    		return 0;
    	}
    	if(r->left==NULL && r->right==NULL)
    	{
    		return 1;
    	}
    	else
    	{
    		return leafNodes(r->left)+leafNodes(r->right);
    	}
    }
    int intermediateNodes(TreeNode* r)
	{
		if((r==NULL)||(r->left==NULL && r->right==NULL))
		{
			return 0;
		}
		return 1+intermediateNodes(r->left)+intermediateNodes(r->right);
	}

    void delete_tree_rec(TreeNode* r){
    	if(r==NULL)
    		return;
    	delete_tree_rec(r->left);
    	delete_tree_rec(r->right);
    	cout << "\nDeleting node:" << r->data;
    	delete r;
    }

    TreeNode* getRoot(){
        return root;
    }
    void setRoot(TreeNode* root){
        this->root = root;
    }

};

int main(){
    BinaryTree b1;
    cout << "\n<-----------------MENU----------------->"
            "\n1. Add a node (Using Iteration): "
    		"\n0. print the tree in 2D :"
            "\n2. Display the tree (Using Recursion): "
            "\n3. Display the tree (Using Iteration): "
            "\n4. Get the height of the tree (Using Recursion): "
            "\n5. Get the height of the tree (Using Iteration): "
            "\n6. Copy the tree recursively and compare: "
            "\n7. Copy the tree iteratively and compare: "
            "\n8. Swap the tree recursively and compare: "
            "\n9. Swap the tree iteratively and compare: "
            "\n10. Add a node (Using Recursion): "
    		"\n11. Count number of leaf nodes and intermediate nodes"
    		"\n12. Erase all the nodes in the tree and EXIT"
            "\n<--------------------------------------->";
    int choice;
    bool flag = true;

    while (flag){
        cout << "\nEnter your choice :";
        cin >> choice;

        switch (choice)
        {
            case 1:
            {
                int data;
                cout << "\nEnter the data to be added: ";
                cin >> data;
                b1.add_node_itr(data);
                break;
            }
            case 0:
            	b1.print2D(b1.getRoot(),5);
            	cout << endl;
            	break;
            case 2:
                cout << "\n\nThe input tree using recursion is: ";
                cout << "\nInorder: ";
                b1.inorder_rec(b1.getRoot());
                cout << "\nPostorder: ";
                b1.postorder_rec(b1.getRoot());
                cout << "\nPreorder: ";
                b1.preorder_rec(b1.getRoot());
                cout << "\n";
                break;
            case 3:
                cout << "\n\nThe input tree using itertion is: ";
                cout << "\nInorder: ";
                b1.inorder_itr();
                cout << "\nPostorder: ";
                b1.postorder_itr();
                cout << "\nPreorder: ";
                b1.preorder_itr();
                cout << "\n";
                break;
            case 4:
                cout << "\nHeight of the tree using recursion is: " << b1.height_rec(b1.getRoot()) << endl;
                break;
            case 5:
                cout << "\nHeight of the tree using iteration is: " << b1.height_itr() << endl;
                break;
            case 6:
            {
                BinaryTree b2 = b1;
                cout << "\nThe input tree is: ";
                cout << "\nInorder: ";
                b1.inorder_itr();
                cout << "\nPostorder: ";
                b1.postorder_itr();
                cout << "\nPreorder: ";
                b1.preorder_itr();
                cout << "\n\nThe copied tree using recursion is: ";
                cout << "\nInorder: ";
                b2.inorder_itr();
                cout << "\nPostorder: ";
                b2.postorder_itr();
                cout << "\nPreorder: ";
                b2.preorder_itr();
                cout << "\n";
                break;
            }
            case 7:
            {
                BinaryTree b2 = b1;
                cout << "\nThe input tree is: ";
                cout << "\nInorder: ";
                b1.inorder_itr();
                cout << "\nPostorder: ";
                b1.postorder_itr();
                cout << "\nPreorder: ";
                b1.preorder_itr();
                cout << "\n\nThe copied tree using iteration is: ";
                cout << "\nInorder: ";
                b2.inorder_itr();
                cout << "\nPostorder: ";
                b2.postorder_itr();
                cout << "\nPreorder: ";
                b2.preorder_itr();
                cout << "\n";
                break;
            }
            case 8:
            {
                cout << "\nThe input tree using iteration is: ";
                cout << "\nInorder: ";
                b1.inorder_itr();
                cout << "\nPostorder: ";
                b1.postorder_itr();
                cout << "\nPreorder: ";
                b1.preorder_itr();

                BinaryTree b2 = b1;
                b2.swap_rec(b2.getRoot());

                cout << "\n\nThe swapped tree using recursion is: ";
                cout << "\nInorder: ";
                b2.inorder_itr();
                cout << "\nPostorder: ";
                b2.postorder_itr();
                cout << "\nPreorder: ";
                b2.preorder_itr();
                cout << "\n";
                b2.print2D(b2.getRoot(), 5);
                cout << "\n";
                break;
            }
            case 9:
            {
                cout << "\nThe input tree using iteration is: ";
                cout << "\nInorder: ";
                b1.inorder_itr();
                cout << "\nPostorder: ";
                b1.postorder_itr();
                cout << "\nPreorder: ";
                b1.preorder_itr();

                BinaryTree b2 = b1;
                b2.swap_itr();

                cout << "\n\nThe swapped tree using iteration is: ";
                cout << "\nInorder: ";
                b2.inorder_itr();
                cout << "\nPostorder: ";
                b2.postorder_itr();
                cout << "\nPreorder: ";
                b2.preorder_itr();
                cout << "\n";
                b2.print2D(b2.getRoot(), 5);
                cout << "\n";
                break;
            }
            case 10:
            {   int data;
                cout << "\nEnter the data to be added: ";
                cin >> data;
                b1.add_input(data);
                break;
            }

            case 11:
            	cout << "\nNumber of leaf nodes in the tree :";
            	cout << b1.leafNodes(b1.getRoot());
            	cout << "\nNumber of intermediate node in the tree :";
            	cout << b1.intermediateNodes(b1.getRoot());
            	cout << endl;
            	break;
            case 12:
            	b1.delete_tree_rec(b1.getRoot());
            	cout << "\nAll tree nodes deleted successfully!" << endl;
            	cout << "\n";
                cout << "\nEXIT, Good Bye!" << endl;
                flag = false;
                break;
            default:
                cout << "\nEnter proper option number!" << endl;
        }
    }
    return 0;
}

