#include<bits/stdc++.h>
using namespace std;
class node{
    public:
    node* parent;
    node* left;
    node* right;
    int data;
    void insert_node(node* &root,int key){
        if(root->data==key){
            cout<<"already present"<<endl;
    }else if(root->data>key){
    if(root->left==NULL){
        root->left=new node;
        root->left->data=key;
        root->left->left=NULL;
        root->left->right=NULL;
        root->left->parent=root;
    }else{
    insert_node(root->left,key);
    }
    }else if(root->data<key){
    if(root->right==NULL){
        root->right=new node;
        root->right->data=key;
        root->right->left=NULL;
        root->right->right=NULL;
        root->right->parent=root;
    }else{
    insert_node(root->right,key);
    }
    }
        }


    node* searcher(node* root,int key){
    if(root==NULL){
        cout<<"value is not present"<<endl;
        return NULL;
    }else if(root->data==key){
    return root;
    }else if(root->data >key){
    searcher(root->left,key);
    }else if(root->data<key){
            searcher(root->right,key);
            }
    }



    node* maxim(node* root){
        node* temp=root;
    while(temp->right!=NULL){
        temp=temp->right;
    }
    return temp;
    }
    node* minim(node* root){
        node* temp=root;
        while(temp->left!=NULL){
            temp=temp->left;
        }
        return temp;
    }


       node* pred(node* root,int key){
       node* temp=searcher(root,key);
       if (temp==NULL){
        cout<<"no key found"<<endl;
        return NULL;
       }
       if(temp->left!=NULL){
        return maxim(temp->left);
       }else{
       while(temp==temp->parent->left){
        temp=temp->parent;
       }
       return temp->parent;
       }

       }



       node* succ(node* root,int key){
           node* temp=searcher(root,key);
           if(temp=NULL){
            cout<<"no key found"<<endl;
        return NULL;
           }
           if(temp->right!=NULL){
            return minim(temp->right);
           }else{
           while(temp=temp->parent->right){
            temp=temp->parent;
           }
           return temp->right;
           }
       }

        node* deleter(node* root,int key){
            if(root==NULL){
                return root;
            }
        if(root->data<key){
            root->right=deleter(root->right,key);
            return root;
        }else if(root->data>key){
            root->left=deleter(root->left,key);
            return root;
        }else{
                if(root->right==NULL){
                node* var=root->left;
                delete (root);
                return var;

              }
              else if(root->left==NULL){
                node* var=root->right;
                delete root;
                return var;

              }else if(root->left!=NULL&&root->right!=NULL){
                int value=succ(root,root->data)->data;
                root->right=deleter(root->right,succ(root,root->data)->data);
                root->data=value;
                return root;
              }


        }
        }

        };
        void inorder(node* root){
            if(root==NULL){
                return;
            }
        inorder(root->left);
        cout<<root->data<<" ";
        inorder(root->right);
        cout<<endl;
        }

int main(){
int n;
cout<<"how many?"<<endl;
cin>>n;
cout<<"give inputs"<<endl;
node* root=new node;
root->parent=NULL;
root->right=NULL;
root->left=NULL;
cin>>root->data;
for(int i=0;i<n-1;i++){
        int m;
    cin>>m;
    root->insert_node(root,m);
}
cout<<"whose predecessor y u?"<<endl;
int key;
cin>>key;
if(root->pred(root,key)!=NULL){
cout<<(root->pred(root,key))->data<<endl;}else{
cout<<"no predecessro"<<endl;
}
cout<<"which one u del?"<<endl;
cin>>key;
root->deleter(root,key);
cout<<"which one u ser?"<<endl;
cin>>key;
node* herrr=root->searcher(root,key);
inorder(root);
}
