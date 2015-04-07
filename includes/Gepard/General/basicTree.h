///////////////////////////////////////////////////////////
//  basicTree.h
//  ����������	Class basicTree
//  �������:   	15-���-2010 23:13:55
//  �����:		Dr_Freeman
///////////////////////////////////////////////////////////

#if !defined(EA_BC0E044D_8FBA_4d22_82D1_57FD24C9BD17__INCLUDED_)
#define EA_BC0E044D_8FBA_4d22_82D1_57FD24C9BD17__INCLUDED_

#include "std_inc.h"

namespace Gepard
{
    namespace General
    {
        /**
         * ����� - ������, ���� ���� - ���� �����
         */
        template<typename T>
        class basicTree
        {
        public:

            //������������ ��� ��������
            typedef T				value_type;
            typedef value_type*		v_pointer;
            typedef value_type&		v_reference;

            typedef basicTree*		basicTreePtr;
            typedef basicTree&		basicTreeRef;

            class basicTreeNode;
            typedef basicTreeNode*		basicTreeNodePtr;
            typedef basicTreeNode&		basicTreeNodeRef;

                /**
                * ����� - ���� ������, �����
                */				
                class basicTreeNode
                {		
                    basicTreeNodePtr _Parent;
                    std::vector<basicTreeNodePtr> _Children;
                    T _Data;
                //-----------------------------------------------------------------
                    public:
                        basicTreeNode()										:_Parent(NULL){};
                        explicit basicTreeNode(T nodeData)					:_Data(nodeData),_Parent(NULL){};
                        basicTreeNode(T nodeData, basicTreeNodePtr parent)	:_Data(nodeData),_Parent(NULL){};
                        ~basicTreeNode() {clear();}

                        /**
                        * �������� ������ ����
                        */
                        T& getData() { return _Data;}

                        /**
                        * �������� ��������� �� ������ ����
                        */
                        T* getDataPtr() { return &_Data;}

                        /**
                        * �������� ���������� �����
                        */
                        unsigned int getCount() const { return _Children.size();}

                        /**
                        * �������� ������� �� ������
                        */
                        basicTreeNodePtr getChild(unsigned int index) { return _Children[index];}

                        /**
                        * �������� ������
                        */
                        basicTreeNodePtr getParent() {return _Parent;}

                        /**
                        * ���������� ������
                        */
                        void setParent(basicTreeNodePtr parentNode) {_Parent = parentNode;}

                        /**
                        * ���� �� �������
                        */
                        bool isChildrenExist() const { return (getCount()>0); }

                        /**
                        * �������� �������
                        */
                        void addChild(basicTreeNodePtr child) 
                        {
                            child->setParent( this );
                            _Children.push_back(child);							
                        }

                        /**
                        *	������� ���������. ���� isDeleteMemory=true, ������� ������!
                        */
                        void deleteNodePtr(basicTreeNodePtr _nodePtr, bool isDeleteMemory=false)
                        {
                            std::vector<basicTreeNodePtr>::iterator _itr;
                            for (_itr=_Children.begin(); _itr!=_Children.end(); _itr++)
                            {
                                if (_nodePtr==*(_itr)) 
                                {
                                    if (isDeleteMemory) delete (*(_itr));
                                    _Children.erase(_itr);
                                    return ;
                                }

                            }//for
                        }

                        /**
                        * ������� ���� ��������
                        */
                        void clear() 
                        {
                            unsigned int countChilds = getCount();
                            for (unsigned int i=0; i<countChilds; i++) delete _Children[i];						
                            _Children.clear();
                        }
                //-----------------------------------------------------------------
                //-----------------------------------------------------------------
                };
        //��������� ����� - ���� ������

                //������� ������� � ������ � �������
                static v_reference getValue(const basicTreeNodePtr _node)					{ return ( _node->getData() ); }
                static v_reference getChild(const basicTreeNodePtr _node, unsigned int i)	{ return ( _node->getChild(i) ); }
                static v_reference getParent(const basicTreeNodePtr _node)					{ return ( _node->getParent() ); }


                //��������� ����� - �������� ��� ������ ������� ������
                class bt_iterator
                {
                private:
                    basicTreeNodePtr	_Current;	//��������� �� ������� ����
                    basicTreePtr		_Tree;		//��������� �� ������-��������

                    std::stack<basicTreeNodePtr> _Stack; //���� ��� �������� "����" ������		

                public:
                    //-----------------------------------------------------------------
                    bt_iterator(basicTreeRef _tree, basicTreeNodePtr _start_node)		:_Tree(&_tree), _Current(_start_node) {}
                    bt_iterator(const bt_iterator& iter)								{ (*this) = iter ; }
                    //-----------------------------------------------------------------

                    /**
                    *	��������� ��� ���������
                    */
                    bt_iterator& operator++ ()
                    {
                        if (_Current)
                            for (int i = _Current->getCount() - 1; i >= 0; i--)
                                _Stack.push( _Current->getChild(i) );

                        if (!_Stack.empty() ) 
                        {
                            _Current = _Stack.top();
                            _Stack.pop();
                        } else *this = _Tree->end();

                        return (*this);
                    }

                    /**
                    *	��� ������ � ������������ ���� if/else
                    */
                    operator bool ()	{ return (_Current !=NULL); }

                    /**
                    *	���������� ���������� (�����������)
                    */
                    const bt_iterator& operator = (const bt_iterator& iter)
                    {
                        _Tree = iter._Tree;
                        _Current = iter._Current;				
                        while (! _Stack.empty() ) _Stack.pop();


                        //������ ��������� �����
                        typedef std::vector <basicTreeNodePtr> NodesVec;
                        NodesVec v ( iter._Stack.size() );

                        bt_iterator& it = const_cast <bt_iterator&> (iter);	
                        while (! it._Stack.empty() ) 
                        {
                            v.push_back ( it._Stack.top() );
                            it._Stack.pop(); 
                        }

                        //��������� ��� �����
                        for (int i = v.size() - 1; i >= 0; i-- ) 
                        {
                            it._Stack.push ( v [i] ); 
                            _Stack.push ( v [i] ); 
                        }
                        return (*this);
                    }

                    /**
                    *	��������� ���� ���������� - ������������ ������ ���������
                    */
                    bool operator == (const bt_iterator& iter) const
                    {
                        if (_Current == iter._Current  &&  _Tree == iter._Tree  && _Stack.size() == iter._Stack.size() )
                            return (true);
                        else
                            return (false);
                    }

                    /**
                    *	����������� ���� ����������
                    */
                    bool operator != (const bt_iterator& iter) const		{	return (! operator == (iter) ); 	}

                    /**
                    * �������� ������ �� ��������
                    */
                    v_reference operator*() const	{return ( getValue(_Current) );}

                    /**
                    * �������� ��������� �� ��������
                    */
                    v_pointer operator->() const {	return (&**this);	}

                    /**
                    * �������� ��������� ������� ��������
                    */
                    basicTreeNodePtr getCurrentNode() 
                    {
                        return _Current;
                    }

                    //-----------------------------------------------------------------
                    //-----------------------------------------------------------------

                };
                //��������� ����� - �������� ��� ������ ������� ������

        private:
            basicTreeNode *_Root; //������ ������ ������

        public:

            basicTree()									:_Root(NULL){};
            explicit basicTree(basicTreeNodePtr root)	:_Root(root){};
            ~basicTree(){ }

            /**
            *	��������� ������
            */
            void setRoot(basicTreeNodePtr root)
            {
                if (_Root) delete (_Root);
                _Root = root;
            }

            /**
            *	�������� ������ ������ ���������������
            */
            basicTreeNodePtr getRoot() 
            {
                return _Root;
            }

            /**
            *	�������� ������ ������
            */
            bt_iterator begin ()		
            {	
                return ( bt_iterator ( *this, _Root) );		
            }

            /**
            *	����� ������
            */
            bt_iterator end ()			
            {	
                return ( bt_iterator ( *this, NULL ) );		
            }

            /**
            *	������� ������
            */
            void clear()
            {
                erase(getRoot());
                if (_Root) delete _Root;
                _Root = NULL;
            }

            protected:

            /**
            * ������� ���������� ������� � _node
            */
            void erase(basicTreeNodePtr _node)
            {
                if (!_node) return;
                if (_node->isChildrenExist())
                {
                    for (unsigned int i=0; i<_node->getCount(); i++)
                    {
                        basicTreeNodePtr _child = _node->getChild(i);
                        if (_child->isChildrenExist()) erase(_child);						
                    }
                    _node->clear();					
                }
            }

        };

    }//end namespace

}//end namespace
#endif // !defined(EA_BC0E044D_8FBA_4d22_82D1_57FD24C9BD17__INCLUDED_)
