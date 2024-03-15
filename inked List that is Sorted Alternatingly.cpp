Node* reverse(Node* head)
    {
        Node* prev = nullptr;
        while(head)
        {
            Node* nex = head->next;
            head->next = prev;
            prev = head;
            head = nex;
        }
        return prev;
    }
    
    void sort(Node **head)
    {
         // Code here
         
        //  Time Complexity -> O(n)
        //  Space Complexity -> O(1)
         
         Node* temp = *head;
         
         Node* asc = new Node(0), *dsc = new Node(0); 
         Node* ascPtr = asc, *dscPtr = dsc;
         
         bool flag = true;
         
         while(temp)
         {
             if(flag)
             {
                 ascPtr->next = temp;
                 ascPtr = ascPtr->next;
             }
             else
             {
                dscPtr->next = temp;
                dscPtr = dscPtr->next;
             }
             temp = temp->next;
             flag ^= 1;
         }
         
         Node* rev = reverse(dsc->next);
    }
