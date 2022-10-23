
template <typename T>
class forward_list
{
 //! Struct of node of the list
    struct Node
    {
        Node* pNext;
        T value;

        Node() : pNext(nullptr)
        {

        };

        bool operator!=(const Node& other) const {
            if (value != other.value || pNext == other.pNext)
                return true;

            return false;
        };

        bool operator==(const Node& other) const {
            if (value != other.value) return false;
            if (pNext != other.pNext) return false;
            return true;
        };
    };

public:

    class iterator
    {
        public:

        iterator();
        iterator(Node* pNode) : pCurrent(pNode) {};

        iterator& operator++(){
            if (pCurrent){
                pCurrent = pCurrent->pNext;     
            }
            return *this;
        };

        iterator& operator++(int d){
            if (pCurrent){
                pCurrent = pCurrent->pNext;     
            }
            return *this;
        };

        iterator& operator=(const iterator& other){
            pCurrent = other.pCurrent;
            return *this;
        }

        bool operator!=(const iterator& other) const {
            return pCurrent != other.pCurrent;
        }

        bool operator==(const iterator& other) const {
            return pCurrent == other.pCurrent;
        }

        T& operator*() {return pCurrent->value;};

        private:

        Node* pCurrent;
    };

    forward_list() : mpFront(nullptr), mpBack(mpFront), mSize(0) {};
    
    ~forward_list()
    {
        Node* pNext = nullptr;
        while (mpFront){
            pNext = mpFront->pNext;
            delete mpFront;
            mpFront = pNext;
        }
    };

    //! Push element to front of the list
    void push_front(const T& value)
    {
        Node* pNode = new Node;
        pNode->value = value;
        pNode->pNext = mpFront;
        mpFront = pNode;
        mSize++;
    };

    //! Pop element from front of the list
    void pop_front()
    {
        if (mSize <= 0) return;

        Node* pTemp = mpFront;
        mpFront = pTemp->pNext;
        if (!pTemp){
            delete pTemp;
        }
        mSize--;
    };

    //! Get list size
    //! @return - list size
    size_t size() {return mSize;};
    //! Access to the first element of list
    //! @return - reference to the first element of list
    T& front() const {if (mpFront) return mpFront->value;};
    //! Generates an iterator over the first element of the list
    //! @return - iterator to the first list element
    iterator begin() const {return iterator(mpFront);};
    //! Generates an iterator over the element before last list element
    //! @return - iterator to the elelemt before last list element
    iterator end() const {return iterator(mpBack);};
    //! 
    bool empty() const {return mSize == 0 ? true : false;};

private:

    //! Pointer to the front node of the list
    Node* mpFront;
    //! Pointer to the end placeholder
    Node* mpBack;
    //! Size of the list
    size_t mSize;

};