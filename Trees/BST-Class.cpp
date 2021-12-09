#include <iostream>
class BSTNode
{
private:
    int data;
    BSTNode *left;
    BSTNode *right;

public:
    BSTNode(int data)
    {
        this->data = data;
        this->left = NULL;
        this->right = NULL;
    }
    ~BSTNode();

    void insert(int data)
    {
        if (data <= this->data)
        {
            if (this->left == NULL)
            {
                this->left = new BSTNode(data);
            }
            else
            {
                this->left->insert(data);
            }
        }
        else
        {
            if (this->right == NULL)
            {
                this->right = new BSTNode(data);
            }
            else
            {
                this->right->insert(data);
            }
        }
    }

    void print_node()
    {
        std::cout << "Value at the node: " << this->data << std::endl;
        if (this->left != NULL)
            std::cout << "Value at left node: " << this->left->data << std::endl;
        if (this->right != NULL)
            std::cout << "Value at right node: " << this->right->data << std::endl;
    }

    bool find(int val)
    {
        if (this->data == val)
        {
            std::cout << "Found" << std::endl;
            return true;
        }
        else if (val <= this->data)
        {
            if (this->left == NULL)
            {
                std::cout << "Not found" << std::endl;
                return false;
            }
            else
            {
                return (this->left)->find(val);
            }
        }
        else
        {
            //std::cout << "It's here" << std::endl;
            if (this->right == NULL)
            {
                std::cout << "Not found" << std::endl;
                return false;
            }
            else
            {
                //std::cout << "passing" << std::endl;
                return (this->right)->find(val);
            }
        }
        std::cout << "Something wrong while trying to find" << std::endl;
        return false;
    }
};

int main()
{
    BSTNode *root = new BSTNode(10);
    root->print_node();
    root->insert(9);
    root->insert(7);
    root->insert(6);
    root->print_node();
    root->insert(14);
    root->print_node();
    std::cout << "Finding 10: " << root->find(10) << std::endl;
    std::cout << "Finding 8: " << root->find(8) << std::endl;
    root->insert(19);
    root->insert(70);
    root->insert(3);
    root->print_node();
    root->insert(4);
    root->insert(8);
    root->print_node();
    std::cout << "Finding 70: " << root->find(70) << std::endl;
    std::cout << "Finding 8: " << root->find(8) << std::endl;
    std::cout << "Finding 17: " << root->find(17) << std::endl;
}