// https://www.interviewbit.com/problems/nearest-smaller-element/

/**
Nearest Smaller Element
Asked in:  
Amazon
Microsoft
Given an array, find the nearest smaller element G[i] for every element A[i] in the array such that the element has an index smaller than i.

More formally,

    G[i] for an element A[i] = an element A[j] such that 
    j is maximum possible AND 
    j < i AND
    A[j] < A[i]
Elements for which no smaller element exist, consider next smaller element as -1.

Input Format

The only argument given is integer array A.
Output Format

Return the integar array G such that G[i] contains nearest smaller number than A[i].If no such element occurs G[i] should be -1.
For Example

Input 1:
    A = [4, 5, 2, 10, 8]
Output 1:
    G = [-1, 4, -1, 2, 2]
Explaination 1:
    index 1: No element less than 4 in left of 4, G[1] = -1
    index 2: A[1] is only element less than A[2], G[2] = A[1]
    index 3: No element less than 2 in left of 2, G[3] = -1
    index 4: A[3] is nearest element which is less than A[4], G[4] = A[3]
    index 4: A[3] is nearest element which is less than A[5], G[5] = A[3]
    
Input 2:
    A = [3, 2, 1]
Output 2:
    [-1, -1, -1]
Explaination 2:
    index 1: No element less than 3 in left of 3, G[1] = -1
    index 2: No element less than 2 in left of 2, G[2] = -1
    index 3: No element less than 1 in left of 1, G[3] = -1
    
    **/

// CODE

vector<int> Solution::prevSmaller(vector<int> &A) {
    int n = A.size();
    if(n==0) return A;
    
    stack<int> st;
    st.push(A[0]);
    A[0] = -1;
    for(int i=1;i<n;i++){
        int prevSmall = -1;
        while(!st.empty() and st.top() >= A[i]) st.pop();
        if(!st.empty()) prevSmall = st.top();
        st.push(A[i]);
        A[i] = prevSmall;
    }
    return A;
}
