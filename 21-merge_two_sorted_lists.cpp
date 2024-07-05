/*
You are given the heads of two sorted linked lists list1 and list2.

Merge the two lists into one sorted list. The list should be made by splicing together the nodes of the first two lists.

Return the head of the merged linked list.

--------------------------------------------
Constraints:

    The number of nodes in both lists is in the range [0, 50].
    -100 <= Node.val <= 100
    Both list1 and list2 are sorted in non-decreasing order.

*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

#include <iostream>
#include <iostream>

using namespace std;

struct ListNode
{
    int val;        // value stored in node
    ListNode *next; // pointer to next node in the list

    // default constructor - creates obkect with no value and no pointer to next obj.
    ListNode() : val(0), next(nullptr) {}

    // constructor with  single parameter to initialize value.
    ListNode(int x) : val(x), next(nullptr) {}

    // constructor with two parameters to initialize value and next pointer.
    ListNode(int x, ListNode *next) : val(x), next(next) {} //
};

class Solution
{
public:
    ListNode *mergeTwoLists(ListNode *list1, ListNode *list2)
    {
        if (list1 == NULL)
        {
            return list2;
        }
        else if (list2 == NULL)
        {
            return list1;
        }

        // initializing pointer for head of merged list. for now let it point to head of list1
        ListNode *ptr = list1;

        /* now add logic for either:
            1. if first element of list1 is greater than first element of list2 then shift head pointer of list1 to next value.
            or
            2. if first element of list2 is greater, then point ptr var to shift 2 head and shift head pointer of list2 to next value.
        */

        if (list1->val > list2->val)
        {
            ptr = list2;
            list2 = list2->next;
        }
        else
        {
            list1 = list1->next;
        }

        // now our merged list is ready to be formed and head pointer of merged list is now curr var.
        ListNode *curr = ptr;

        while (list1 && list2)
        {
            if (list1->val > list2->val)
            {
                curr->next = list1;
                list1 = list1->next;
            }
            else
            {
                curr->next = list2;
                list2 = list2->next;
            }
            curr = curr->next;
        }

        // if either of the lists are empty, add the other list to the end of the merged list. (since both lists are already merged.)
        if (!list1)
        {
            curr->next = list2;
        }
        else if (!list2)
        {
            curr->next = list1;
        }

        return ptr;
    }
};

int main()
{
    printf("print sample for main.");
}