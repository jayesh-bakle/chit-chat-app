#include <bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    struct Node* left;
    struct Node* right;

    Node(int val)
    {
        data = val;
        left = right = NULL;
    }
};

void preorder(Node* root)
{
    if(root==NULL)return;

    cout<<root->data<<" ";
    preorder(root->left);
    preorder(root->right);
}

vector<int> pre(Node* root)
{
    vector<int>ans;
    stack<Node*>st;
    if(root==NULL)return ans;
    st.push(root);

    while(!st.empty())
    {
        Node* temp = st.top();
        st.pop();
        ans.push_back(temp->data);

        if(temp->right!=NULL)st.push(temp->right);
        if(temp->left!=NULL)st.push(temp->left);
    }
    return ans;
}

vector<int> in(Node* root)
{
    vector<int>ans;
    stack<Node*>st;
    
    while(1)
    {

    if(root!=NULL)
    {
        st.push(root);
        root = root->left;
    }
    else{
        if(st.empty())return ans;

        root = st.top();
        st.pop();
        ans.push_back(root->data);
        root = root->right;
    }
    }
    return ans;
}


vector<int> post(Node* root)
{
        vector<int>ans;
    stack<Node*>st;
    if(root==NULL)return ans;
    st.push(root);

    while(!st.empty())
    {
        Node* temp = st.top();
        st.pop();
        ans.push_back(temp->data);

        if(temp->left!=NULL)st.push(temp->left);
        if(temp->right!=NULL)st.push(temp->right);
    }
    reverse(ans.begin(),ans.end());
    return ans;
}
vector<vector<int>> level(Node* root)
{
    vector<vector<int>>ans;
    if(root==nullptr)return ans;
    queue<Node*>q;

    q.push(root);
    bool flag = true;
    while(!q.empty())
    {
        int size = q.size();
        vector<int>v(size);

        for(int i=0;i<size;i++)
        {
            Node* temp = q.front();
            q.pop();


            if(temp->left){
                q.push(temp->left);
            }
             if(temp->right){
                q.push(temp->right);
            }
            if(flag==true)
            {
                v[i] = temp->data;
            }
            else{
                v[size-i-1] = temp->data;
            }
            // v.push_back(temp->data);

        }
        flag = !flag;
        ans.push_back(v);
    }
    return ans;
}

int maxDepth(Node* root,int& maxi)
{
    if(root==nullptr)return 0;

    int lh = maxDepth(root->left,maxi);
    int rh = maxDepth(root->right,maxi);

    maxi = max(maxi,lh+rh);

    return 1 +  max(lh,rh);
}

int diameter(Node* root)
{
    int maxi = 0;
    maxDepth(root,maxi);

    return maxi;
}


int main()
{
    struct Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->right = new Node(5);

    // cout<<diameter(root)<<endl;

    // preorder(root);

    // vector<int>v = pre(root);
    //  vector<int>v = in(root);
    //  vector<int>v = post(root);

     vector<vector<int>>v = level(root);

     for(int i=0;i<v.size();i++)
     {
        for(int j=0;j<v[i].size();j++)
        {
            cout<<v[i][j]<<" ";
        }
        cout<<endl;
     }

    // for(auto it:v)cout<<it<<" ";


    stack<pair<Node*,int>>st;
    st.push(make_pair(root,1));
    vector<int>pre,in,post;

    while(!st.empty())
    {
        auto it = st.top();
        st.pop();

        if(it.second==1)
        {
            pre.push_back(it.first->data);
            it.second++;
            st.push(it);

            if(it.first->left!=NULL)
            {
                st.push(make_pair(it.first->left,1));
            }
        }
        else if(it.second==2)
        {
            in.push_back(it.first->data);
            it.second++;
            st.push(it);

            if(it.first->right!=NULL)
            {
                st.push(make_pair(it.first->right,1));
            }
        }
        else{
            post.push_back(it.first->data);
        }
    }

    // for(auto it:pre)cout<<it<<" ";
    // for(auto it:in)cout<<it<<" ";
    // for(auto it:post)cout<<it<<" ";



    return 0;
}