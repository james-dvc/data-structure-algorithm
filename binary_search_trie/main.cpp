#include <iostream>
#include <memory>
#include <queue>

template<class T>
struct Node {
	explicit Node(T d): data(d) {}
	T data;
	using node_ptr_t = std::unique_ptr<Node<T>>;
	node_ptr_t left = nullptr;
	node_ptr_t right = nullptr;
}; 

template<class T>
void insert(Node<T>& root, T data)
{
	auto fill_node = [data](std::unique_ptr<Node<T>>& node) {
		if (node)
			insert(*node, data);
		else
			node = std::make_unique<Node<T>>(data);
	};
	if (data <= root.data)
		fill_node(root.left);
	else
		fill_node(root.right);
}

template<class T>
size_t height(const Node<T>* root)
{
	if (!root || (root->left == nullptr&&root->right == nullptr))
		return 0;
	size_t left = 0, right = 0;
	if (root->left) left = height(root->left.get()) + 1;
	if (root->right) right = height(root->right.get()) + 1;
	return std::max(left, right);
}

template<class T>
void print_bfs_queue(const Node<T>* root)
{
	std::queue<const Node<T>*> q; // current level
	q.push(root);
	while (!q.empty()) { 
		size_t node_count = q.size(); // current level node count
		// print each node in current level
		// and prepare for the next level
		while (node_count > 0) {
			auto node = q.front();
			if (node)
				std::cout << node->data << " ";
			q.pop();
			// add nodes in next level
			if (node->left)
				q.push(node->left.get());
			if (node->right)
				q.push(node->right.get());
			--node_count;
		}
		// finish a level
		std::cout << std::endl;
	}	
}

int main() {
	/*Code to test the logic*/
	auto root = Node<int>{ 15 };// Create first node
	insert(root, 10);
	insert(root, 20);
	insert(root, 25);
	insert(root, 8);
	insert(root, 12);
	print_bfs_queue(&root);
	std::cout << "Tree height = " << height(&root);
	return 0;
}