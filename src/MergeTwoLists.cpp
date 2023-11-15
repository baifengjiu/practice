//
// Created by Amy on 2023/6/14.
//
#include <iostream>
#include <vector>

//Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode * result = nullptr;
        if (list1 == nullptr && list2 == nullptr) {
            return result;
        }

        result = new ListNode();
        ListNode *root = result;
        while (list1 != nullptr || list2 != nullptr) {
            if (list2 == nullptr || (list1 != nullptr && list2 != nullptr && list1->val <= list2->val)) {
                result->val = list1->val;
                list1 = list1->next;
            } else if (list1 == nullptr || (list1 != nullptr && list2 != nullptr && list1->val >= list2->val)) {
                result->val = list2->val;
                list2 = list2->next;
            }
            if (list1 || list2) {
                result->next = new ListNode();
                result = result->next;
            }
        }

        return root;
    }
};

//
//int main () {
//
//    std::cout <<"============== 开始 \n";
//    std::vector<int> v1 {};
//
//    ListNode *list1 = new ListNode();
//    ListNode *root1 = list1;
//    for (int i = 0;i< v1.size(); i++) {
//        list1->val = v1[i];
//        if (i != v1.size()-1) {
//            list1->next = new ListNode();
//            list1 = list1->next;
//        }
//    }
//
//    std::vector<int> v2{};
//
//    ListNode *list2 = new ListNode();
//    ListNode *root2 = list2;
//    for (int i = 0;i< v2.size(); i++) {
//        list2->val = v2[i];
//        if (i != v2.size()-1) {
//            list2->next = new ListNode();
//            list2 = list2->next;
//        }
//    }
//    Solution s;
//    auto list3 = s.mergeTwoLists(root1, root2);
//
//    std::cout <<" list3:" << list3 << "\n";
//    while ( list3!= nullptr) {
//        std::cout << list3->val << " ";
//        list3 = list3->next;
//    }
//    return 0;
//}