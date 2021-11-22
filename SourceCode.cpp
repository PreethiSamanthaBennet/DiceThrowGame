/* Assume an online board game in which each player tosses dice.
Each time the count of dice is added to the player’s score. 
When the score reaches to 50, the player is eliminated from the game. 
Design algorithm for the board game with n players. */

#include <iostream>
#include <stdlib.h>
#include <ctime>

using namespace std;
/*———————————————————————————————————————————————————————————————————————————*/
int RollTheDie(){  // Random Number Generator
    srand((unsigned) time(0));
    printf("Your dice has been rolled! You got : ");
    int result = (rand() % 6) + 1;
    cout << result << endl;
    return result;
}
/*———————————————————————————————————————————————————————————————————————————*/
class Node{
    public:
        string name;
        int score;
        Node* next;
};
/*———————————————————————————————————————————————————————————————————————————*/
void Insert(Node** head_ref, string new_data){
    
    Node *new_node = new Node();
    Node *temp = *head_ref;
    new_node->name = new_data;
    
    if (*head_ref == NULL)
        new_node->next = new_node;
        
    else{
        while (temp->next != *head_ref)
            temp = temp->next; //last node
            temp->next = new_node;
            new_node->next = (*head_ref);
    }
    (*head_ref) = new_node;
}
/*———————————————————————————————————————————————————————————————————————————*/
int UpdateScore(Node* head, int score){
    head->score = head->score + score;
    return head->score;
}
/*———————————————————————————————————————————————————————————————————————————*/
void Delete(Node* head_ref){
    
    cout << endl << head_ref->name << " ELIMINATED !!  Score - " << head_ref->score<< "\n\n";
    
    // Store head node
    Node* temp = head_ref;
    Node* oldhead = head_ref;
 
    //only one node
    if (temp->next == temp){
        delete head_ref;
        head_ref=NULL;
        return;
    }
    
    while (temp->next != head_ref)
        temp = temp->next; //last node
        
    temp->next = oldhead-> next;  
    head_ref = oldhead->next;   // Changed head
    delete oldhead;   // free old head
    return;
}
/*———————————————————————————————————————————————————————————————————————————*/
int main (){

    Node *head = NULL;
    
    string str;
    int n, choice, result;
    
    cout << "Enter the number of players : ";
    cin >> n;
    cout << endl;
    
    for (int i = 0; i < n; i++){
        cout << "Player " << (i + 1) << " - Enter your Name : ";
        cin >> str;
        Insert(&head, str);
    }
    
    Node *temp = head;
    
    cout << "\nEnter 1 to Roll the Dice, 0 to Exit \n";
    
    while (1 == 1){
            cout << "\n" << temp->name << "'s turn";
            cout << "\nEnter your choice : ";
            cin >> choice;
            
            if (choice == 1){
                result = RollTheDie();
                if (UpdateScore(temp, result) >= 50){
                    Delete(temp);
                }
                temp = temp->next;
            }
            
            if (temp == temp->next){
                cout << "\n" << temp->name << " is the WINNER !!  Score - " << temp->score;
                cout << endl;
                return 0;
            }
            
            if (choice == 0)
                return 0;
    }
    return 0;
}
