#include <stdio.h>
#include <stdlib.h>

typedef  struct {
    int id;
    int left;
    int right;
} Node;

int calculateTreeDepth(Node* nodes, int const idx, int const depth)
{
    const Node node = nodes[idx];
    if (idx == -1)
    {
        return depth - 1;
    }
    const int leftDepth = calculateTreeDepth(nodes, node.left, depth+1);
    const int rightDepth = calculateTreeDepth(nodes, node.right, depth+1);

    return (leftDepth > rightDepth)? leftDepth : rightDepth;
}

int calculateDepth(Node* nodes)
{
    return calculateTreeDepth(nodes, 0, 0);
}

int main(int argc, char *argv[])
{
    int n;
    scanf("%d",&n);

    Node* nodes = (Node*)malloc(sizeof(Node)*n);

    for (int i = 0; i < n; i++)
    {
        Node temp;
        temp.id = i;
        scanf("%d %d",&temp.left,&temp.right);
        nodes[i] = temp;
    }


    /*for (int i = 0; i < n; i++)
        printf("created node: [id: %d, left: %d, right: %d]\n",nodes[i].id, nodes[i].left, nodes[i].right);
*/
    printf("%d\n",calculateDepth(nodes));
    free(nodes);

}
