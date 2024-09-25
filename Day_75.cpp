#include <iostream>

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    bool isPalindrome(ListNode* head) {
        if (head == nullptr || head->next == nullptr)
            return true;
        
        // Find the middle of the linked list
        ListNode* slow = head;
        ListNode* fast = head;
        while (fast->next != nullptr && fast->next->next != nullptr) {
            slow = slow->next;
            fast = fast->next->next;
        }
        
        // Reverse the second half of the linked list
        ListNode* secondHalf = reverseList(slow->next);
        
        // Compare the first half with the reversed second half
        ListNode* firstHalf = head;
        ListNode* secondHalfPtr = secondHalf;
        bool isPalindrome = true;
        while (secondHalfPtr != nullptr) {
            if (firstHalf->val != secondHalfPtr->val) {
                isPalindrome = false;
                break;
            }
            firstHalf = firstHalf->next;
            secondHalfPtr = secondHalfPtr->next;
        }
        
        // Restore the original linked list (optional)
        slow->next = reverseList(secondHalf);
        
        return isPalindrome;
    }
    
private:
    ListNode* reverseList(ListNode* head) {
        ListNode* prev = nullptr;
        ListNode* curr = head;
        while (curr != nullptr) {
            ListNode* nextTemp = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nextTemp;
        }
        return prev;
    }
};

// Helper function to create a linked list from an array
ListNode* createLinkedList(int arr[], int n) {
    if (n == 0) return nullptr;
    ListNode* head = new ListNode(arr[0]);
    ListNode* current = head;
    for (int i = 1; i < n; i++) {
        current->next = new ListNode(arr[i]);
        current = current->next;
    }
    return head;
}

// Helper function to print a linked list
void printLinkedList(ListNode* head) {
    ListNode* current = head;
    while (current != nullptr) {
        std::cout << current->val << " -> ";
        current = current->next;
    }
    std::cout << "nullptr" << std::endl;
}

int main() {
    // Test case 1: Palindrome linked list
    int arr1[] = {1, 2, 1, 1, 2, 1};
    ListNode* head1 = createLinkedList(arr1, 6);
    std::cout << "Test case 1:" << std::endl;
    std::cout << "Input: ";
    printLinkedList(head1);
    
    Solution solution;
    bool result1 = solution.isPalindrome(head1);
    std::cout << "Is palindrome: " << (result1 ? "true" : "false") << std::endl;
    std::cout << "After function call: ";
    printLinkedList(head1);
    std::cout << std::endl;

    // Test case 2: Non-palindrome linked list
    int arr2[] = {1, 2, 3, 4, 5};
    ListNode* head2 = createLinkedList(arr2, 5);
    std::cout << "Test case 2:" << std::endl;
    std::cout << "Input: ";
    printLinkedList(head2);
    
    bool result2 = solution.isPalindrome(head2);
    std::cout << "Is palindrome: " << (result2 ? "true" : "false") << std::endl;
    std::cout << "After function call: ";
    printLinkedList(head2);

    // Free memory (in a real application, you'd want to properly delete all nodes)
    delete head1;
    delete head2;

    return 0;
}