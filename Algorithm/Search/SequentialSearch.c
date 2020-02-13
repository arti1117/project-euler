/*
 *  Sequential.c
 *  
 *  Created on: Aug 12, 2019
 *      Author: arti
 */

/*
    Node* SequentialSearch(Node* head, int target)
    {
        Node* curr = head;
        Node* match = NULL;

        while (curr != NULL)
        {
            if (curr->data == target)
            {
                match = curr;
                break;
            }
            else
                curr = curr->next;
        }
        return match;
    }

    node* moveToFront(node** head, int target)
    {
        node* curr = (*head);
        node* prev = NULL;
        node* match = NULL;

        while (curr != NULL)
        {
            if (curr->data == target)
            {
                match = curr;
                if (prev != NULL)
                {
                    prev->next = curr->next;
                    curr->next = (*head);
                    (*head) = curr;
                }
                break;
            }
            else
            {
                prev = curr;
                curr = curr->next;
            }
            
        }
        return match;
    }

    node* transpose(node** head, int target)
    {
        node* curr = (*head);
        node* prev = NULL;
        node* pprev = NULL;
        node* match = NULL;

        while (curr != NULL)
        {
            if (curr->data == target)
            {
                match = curr;
                if (prev != NULL)
                {
                    if (pprev != NULL)
                        pprev->next = curr;
                    else
                        (*head) = curr;
                    
                    prev->next = curr->next;
                    curr->next = prev;
                }
                break;
            }
            else
            {
                if (prev != NULL)
                    pprev = prev;
                    prev = curr;
                    curr = curr->next;
            }
        }
    }
*/
