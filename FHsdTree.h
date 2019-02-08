/*
 Mian Wei
 assignment10
 12/07
 */


// File FHsdTree.h
// Template definitions for FHsdTrees, which are general trees
#ifndef FHsdTree_H
#define FHsdTree_H
#include <string>

// advanced prototype for the FHsdTreeNode to use to declare a friend
template <class Object>
class FHsdTree;

// ---------------------- FHsdTreeNode Prototype --------------------------
template <class Object>
class FHsdTreeNode
{
    friend class FHsdTree<Object>;
    
protected:
    FHsdTreeNode *firstChild, *sib, *prev;
    Object data;
    FHsdTreeNode *myRoot;  // needed to test for certain error
    bool deleted;
    
public:
    FHsdTreeNode( const Object & d = Object(),
               FHsdTreeNode *sb = NULL, FHsdTreeNode *chld = NULL
                    , FHsdTreeNode *prv = NULL )
    : firstChild(chld), sib(sb), prev(prv), data(d), myRoot(NULL)
    { }
    Object GetData() const { return data; }
    
protected:
    // for use only by FHsdTree
    FHsdTreeNode( const Object & d,
               FHsdTreeNode *sb, FHsdTreeNode *chld, FHsdTreeNode *prv,
               FHsdTreeNode *root, bool del)
    : firstChild(chld), sib(sb), prev(prv), data(d), myRoot(root), deleted(del)
    { }
};

// --------------------------- FHsdTree Prototype ------------------------------
template <class Object>
class FHsdTree
{
protected:
    int mSize;
    FHsdTreeNode<Object> *mRoot;
    
public:
    int size() {return size(mRoot);}
    int size(FHsdTreeNode<Object> *treeNode, int level = 0) const;
    
    
    FHsdTree() { mSize = 0; mRoot = NULL; }
    FHsdTree(const FHsdTree &rhs) { mRoot = NULL; mSize = 0; *this = rhs; }
    virtual ~FHsdTree() { clear(); }
    bool empty() const { return (mSize == 0); }
//    int size() const { return mSize; }
    int sizePhysical () const { return mSize; }
    void clear() { removeNode(mRoot); }
    const FHsdTree & operator=(const FHsdTree &rhs);
    
    FHsdTreeNode<Object> *addChild( FHsdTreeNode<Object> *treeNode,
                                    const Object &x );
    
    FHsdTreeNode<Object> *find(const Object &x) { return find(mRoot, x); }
    FHsdTreeNode<Object> *find(FHsdTreeNode<Object> *root,
                             const Object &x, int level = 0);
    
    bool remove(const Object &x) { return remove(mRoot, x); }
    bool remove(FHsdTreeNode<Object> *root, const Object &x);
    
    void removeNode(FHsdTreeNode<Object> *nodeToDelete);
    bool collectGarbage(FHsdTreeNode<Object> *nodeToDelete);
    bool collectGarbage() {return collectGarbage(mRoot);}
    
    // usual client interfaces (entire tree implied)
    void display() const { display(mRoot, 0); }
    void displayPhysical() const { display(mRoot, 0); }
    template <class Processor>
    void traverse(Processor func) const { traverse(func, mRoot, 0); }
    
    // recursive helpers
    void displayPhysical(FHsdTreeNode<Object> *treeNode, int level = 0) const;
    void display(FHsdTreeNode<Object> *treeNode, int level = 0) const;
    template <class Processor>
    void traverse(Processor func, FHsdTreeNode<Object> *treeNode,
                  int level = 0)const;
    
protected:
    FHsdTreeNode<Object> *clone( FHsdTreeNode<Object> *root) const;
    void setMyRoots(FHsdTreeNode<Object> *treeNode);
};

//#include"FHsdTree.cpp"


// FHsdTree Method Definitions -------------------------------------------------
template <class Object>
void displayPhysical(FHsdTreeNode<Object> *treeNode, int level = 0){
    // this will be static and so will be shared by all calls - a special technique to
    // be avoided in recursion, usually
    static string blankString = "                                    ";
    string indent;
    
    // stop runaway indentation/recursion
    if  (level > (int)blankString.length() - 1)
    {
        cout << blankString << " ... " << endl;
        return;
    }
    
    if (treeNode == NULL)
        return;
    
    indent = blankString.substr(0, level);
    
    cout << indent << treeNode->data  << endl;
    display( treeNode->firstChild, level + 1 );
    if (level > 0)
        display( treeNode->sib, level );
}



template <class Object>
int FHsdTree<Object>::size(FHsdTreeNode<Object> *treeNode,
                           int level) const{
    int nodeSize = 0;
    if (treeNode == nullptr){
        return 0;
    }
    FHsdTreeNode<Object> *curent = treeNode-> firstChild;
    
    //    while(!treeNode->deleted){
    //        size++;
    //    }
    while(curent != nullptr){
        if( !curent->deleted){
            //            int nodeSize = 1;
            nodeSize += size(curent,level+1);
            
        }
        curent = curent-> sib;
    }
    
    return nodeSize +1;
}

template <class Object>
FHsdTreeNode<Object>* FHsdTree<Object>::find(FHsdTreeNode<Object> *root,
                                             const Object &x, int level)
{
    
    FHsdTreeNode<Object> *retval;
    
    if (mSize == 0 || root == NULL)
        return NULL;
    
    if ((root->data == x) && (!root->deleted)){
        
        return root;
    }
    // otherwise, recurse.  don't process sibs if this was the original call
    if ( level > 0 && (retval = find(root->sib, x, level)))
        return retval;
    if(!root->deleted){
        return find(root->firstChild, x, level+1);
    }else {
        return NULL;
    }
}



template <class Object>
bool FHsdTree<Object>::remove(FHsdTreeNode<Object> *root, const Object &x)
{
    FHsdTreeNode<Object> *tn = NULL;
    
    if (mSize == 0 || root == NULL)
        return false;
    
    if ( (tn = find(root, x)) != NULL )
    {
        //        removeNode(tn);
        tn->deleted = true;
        return true;
    }
    return false;
}

template <class Object>
const FHsdTree<Object> &FHsdTree<Object>::operator= (const FHsdTree &rhs)
{
    if (&rhs != this)
    {
        clear();
        mRoot = clone(rhs.mRoot);
        mSize = rhs.mSize;
        setMyRoots(mRoot);
    }
    return *this;
}

template <class Object>
void FHsdTree<Object>::removeNode(FHsdTreeNode<Object> *nodeToDelete)
{
    if (nodeToDelete == NULL || mRoot == NULL)
        return;
    if (nodeToDelete->myRoot != mRoot)
        return;  // silent error, node does not belong to this tree
    
    // remove all the children of this node
    while (nodeToDelete->firstChild)
        removeNode(nodeToDelete->firstChild);
    
    if (nodeToDelete->prev == NULL)
        mRoot = NULL;  // last node in tree
    else if (nodeToDelete->prev->sib == nodeToDelete)
        nodeToDelete->prev->sib = nodeToDelete->sib; // adjust left sibling
    else
        nodeToDelete->prev->firstChild = nodeToDelete->sib;  // adjust parent
    
    // adjust the successor sib's prev pointer
    if (nodeToDelete->sib != NULL)
        nodeToDelete->sib->prev = nodeToDelete->prev;
    
    delete nodeToDelete;
    --mSize;
    
}

template <class Object>
bool FHsdTree<Object>::collectGarbage(FHsdTreeNode<Object> *nodeToDelete){
    if (nodeToDelete == nullptr) {
        return false;
    }
    if(nodeToDelete->deleted){
        removeNode(nodeToDelete);
        collectGarbage(nodeToDelete->sib);
        return true;
    }else {
        bool sib = collectGarbage(nodeToDelete->sib);
        bool firstCh = collectGarbage(nodeToDelete->firstChild);
        return (sib||firstCh);
    }
}

template <class Object>
FHsdTreeNode<Object> *FHsdTree<Object>::addChild(
                                                 FHsdTreeNode<Object> *treeNode
                                                 , const Object &x )
{
    // empty tree? - create a root node if user passes in NULL
    
    if (mSize == 0)
    {
        if (treeNode != NULL)
            return NULL; // silent error -- something's fishy
        mRoot = new FHsdTreeNode<Object>(x, NULL, NULL, NULL);
        mRoot->myRoot = mRoot;
        mSize = 1;
        return mRoot;
    }
    if (treeNode == NULL)
        return NULL; // silent error inserting into a non_null tree with a null parent
    if(treeNode->deleted){
        return NULL;
    }
    
    if (treeNode->myRoot != mRoot)
        return NULL;  // silent error, node does not belong to this tree
    
    // push this node into the head of the sibling list; adjust prev pointers
    FHsdTreeNode<Object> *newNode = new FHsdTreeNode<Object>(x,
                                                             treeNode->firstChild,
                                                             NULL, treeNode,
                                                             mRoot, false);
    // sib, child, prev, root
    treeNode->firstChild = newNode;
    if (newNode->sib != NULL)
        newNode->sib->prev = newNode;
    ++mSize;
    return newNode;
}

template <class Object>
void FHsdTree<Object>::display(FHsdTreeNode<Object> *treeNode, int level) const
{
    // this will be static and so will be shared by all calls - a special technique to
    // be avoided in recursion, usually
    static string blankString = "                                    ";
    string indent;
    
    // stop runaway indentation/recursion
    if  (level > (int)blankString.length() - 1)
    {
        cout << blankString << " ... " << endl;
        return;
    }
    
    if (treeNode == NULL)
        return;
    
    indent = blankString.substr(0, level);
    
    if(!treeNode->deleted){
        cout << indent << treeNode->data  << endl;
        display( treeNode->firstChild, level + 1 );
        if (level > 0)
            display( treeNode->sib, level );
    }else if ((treeNode->deleted)&&(level > 0)){
        display( treeNode->sib, level );
    }
}

template <class Object>
template <class Processor>
void FHsdTree<Object>::traverse(Processor func, FHsdTreeNode<Object> *treeNode
                                , int level)
const
{
    if (treeNode == NULL)
        return;
    
    func(treeNode->data);
    
    traverse(func, treeNode->firstChild, level+1);
    if (level > 0)
        traverse(func, treeNode->sib, level);
}

template <class Object>
FHsdTreeNode<Object> *FHsdTree<Object>::clone(
                                              FHsdTreeNode<Object> *root) const
{
    FHsdTreeNode<Object> *newNode;
    if (root == NULL)
        return NULL;
    
    // does not set myRoot which must be done by caller
    newNode = new FHsdTreeNode<Object>(root->data,
                                       clone(root->sib), clone(root->firstChild)
                                       (root->deleted));
    
    // entire subtree is cloned, but wire this node into its sib and first chld
    if (newNode->sib)
        newNode->sib->prev = newNode;
    if (newNode->firstChild)
        newNode->firstChild->prev = newNode;
    return newNode;
}

template <class Object>
void FHsdTree<Object>::setMyRoots(FHsdTreeNode<Object> *treeNode)
{
    if (treeNode == NULL)
        return;
    
    treeNode->myRoot = mRoot;
    setMyRoots(treeNode->sib);
    setMyRoots(treeNode->firstChild);
}


#endif
/*
 Starting tree empty? 1
 
 
 ------------ Loaded Tree -----------------
 room
 table
 south west leg
 south east leg
 north west leg
 north east leg
 Miguel the human
 torso
 right arm
 right hand
 pinky
 ring finger
 middle finger
 index finger
 thumb
 left arm
 left hand
 pinky
 ring finger
 middle finger
 index finger
 thumb
 Lily the canine
 torso
 wagging tail
 spare mutant paw
 left rear paw
 right rear paw
 left front paw
 right front paw
 
 ------------ Virtual (soft) Tree -----------------
 room
 table
 south west leg
 south east leg
 north west leg
 north east leg
 Lily the canine
 torso
 wagging tail
 left rear paw
 right rear paw
 left front paw
 right front paw
 
 ------------ Physical (hard) Display -----------------
 room
 table
 south west leg
 south east leg
 north west leg
 north east leg
 Lily the canine
 torso
 wagging tail
 left rear paw
 right rear paw
 left front paw
 right front paw
 ------- Testing Sizes (compare with above)-----------
 virtual (soft) size: 13
 physical (hard) size: 30
 ------------ Collecting Garbage --------------------
 found soft-deleted nodes? 1
 immediate collect again? 0
 --------- Hard Display after garb col ------------
 room
 table
 south west leg
 south east leg
 north west leg
 north east leg
 Lily the canine
 torso
 wagging tail
 left rear paw
 right rear paw
 left front paw
 right front paw
 Semi-deleted tree empty? 0
 
 Completely-deleted tree empty? 0
 
 Program ended with exit code: 0
 */
