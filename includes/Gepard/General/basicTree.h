///////////////////////////////////////////////////////////
//  basicTree.h
//  Реализация	Class basicTree
//  Создано:   	15-фев-2010 23:13:55
//  Автор:		Dr_Freeman
///////////////////////////////////////////////////////////

#if !defined(EA_BC0E044D_8FBA_4d22_82D1_57FD24C9BD17__INCLUDED_)
#define EA_BC0E044D_8FBA_4d22_82D1_57FD24C9BD17__INCLUDED_

#include "std_inc.h"

namespace Gepard
{
    namespace General
    {
        /**
         * Класс - дерево, либо граф - тоже самое
         */
        template<typename T>
        class basicTree
        {
        public:

            //переназначим для удобства
            typedef T				value_type;
            typedef value_type*		v_pointer;
            typedef value_type&		v_reference;

            typedef basicTree*		basicTreePtr;
            typedef basicTree&		basicTreeRef;

            class basicTreeNode;
            typedef basicTreeNode*		basicTreeNodePtr;
            typedef basicTreeNode&		basicTreeNodeRef;

                /**
                * Класс - узел дерева, графа
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
                        * Получить данный узел
                        */
                        T& getData() { return _Data;}

                        /**
                        * Получить указатель на данный узел
                        */
                        T* getDataPtr() { return &_Data;}

                        /**
                        * Получить количество узлов
                        */
                        unsigned int getCount() const { return _Children.size();}

                        /**
                        * Получить потомка по номеру
                        */
                        basicTreeNodePtr getChild(unsigned int index) { return _Children[index];}

                        /**
                        * Получить предка
                        */
                        basicTreeNodePtr getParent() {return _Parent;}

                        /**
                        * Установить предка
                        */
                        void setParent(basicTreeNodePtr parentNode) {_Parent = parentNode;}

                        /**
                        * Есть ли потомки
                        */
                        bool isChildrenExist() const { return (getCount()>0); }

                        /**
                        * Добавить потомка
                        */
                        void addChild(basicTreeNodePtr child) 
                        {
                            child->setParent( this );
                            _Children.push_back(child);							
                        }

                        /**
                        *	Удалить указатель. Если isDeleteMemory=true, удаляем память!
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
                        * Удалить всех потомков
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
        //локальный класс - узел дерева

                //функции доступа к данным и листьям
                static v_reference getValue(const basicTreeNodePtr _node)					{ return ( _node->getData() ); }
                static v_reference getChild(const basicTreeNodePtr _node, unsigned int i)	{ return ( _node->getChild(i) ); }
                static v_reference getParent(const basicTreeNodePtr _node)					{ return ( _node->getParent() ); }


                //локальный класс - итератор для обхода листьев дерева
                class bt_iterator
                {
                private:
                    basicTreeNodePtr	_Current;	//указатель на текущий узел
                    basicTreePtr		_Tree;		//указатель на дерево-родитель

                    std::stack<basicTreeNodePtr> _Stack; //стэк для хранения "пути" обхода		

                public:
                    //-----------------------------------------------------------------
                    bt_iterator(basicTreeRef _tree, basicTreeNodePtr _start_node)		:_Tree(&_tree), _Current(_start_node) {}
                    bt_iterator(const bt_iterator& iter)								{ (*this) = iter ; }
                    //-----------------------------------------------------------------

                    /**
                    *	Инкремент для итератора
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
                    *	Для работы в конструкциях типа if/else
                    */
                    operator bool ()	{ return (_Current !=NULL); }

                    /**
                    *	Присвоение итераторов (копирование)
                    */
                    const bt_iterator& operator = (const bt_iterator& iter)
                    {
                        _Tree = iter._Tree;
                        _Current = iter._Current;				
                        while (! _Stack.empty() ) _Stack.pop();


                        //теперь скопируем стеки
                        typedef std::vector <basicTreeNodePtr> NodesVec;
                        NodesVec v ( iter._Stack.size() );

                        bt_iterator& it = const_cast <bt_iterator&> (iter);	
                        while (! it._Stack.empty() ) 
                        {
                            v.push_back ( it._Stack.top() );
                            it._Stack.pop(); 
                        }

                        //заполняем оба стэка
                        for (int i = v.size() - 1; i >= 0; i-- ) 
                        {
                            it._Stack.push ( v [i] ); 
                            _Stack.push ( v [i] ); 
                        }
                        return (*this);
                    }

                    /**
                    *	Сравнение двух итераторов - сравниваются только указатели
                    */
                    bool operator == (const bt_iterator& iter) const
                    {
                        if (_Current == iter._Current  &&  _Tree == iter._Tree  && _Stack.size() == iter._Stack.size() )
                            return (true);
                        else
                            return (false);
                    }

                    /**
                    *	Неравенство двух итераторов
                    */
                    bool operator != (const bt_iterator& iter) const		{	return (! operator == (iter) ); 	}

                    /**
                    * Получить ссылку на значение
                    */
                    v_reference operator*() const	{return ( getValue(_Current) );}

                    /**
                    * Получить указатель на значение
                    */
                    v_pointer operator->() const {	return (&**this);	}

                    /**
                    * Получить указатель текущее значение
                    */
                    basicTreeNodePtr getCurrentNode() 
                    {
                        return _Current;
                    }

                    //-----------------------------------------------------------------
                    //-----------------------------------------------------------------

                };
                //локальный класс - итератор для обхода листьев дерева

        private:
            basicTreeNode *_Root; //корень нашего дерева

        public:

            basicTree()									:_Root(NULL){};
            explicit basicTree(basicTreeNodePtr root)	:_Root(root){};
            ~basicTree(){ }

            /**
            *	Устновить корень
            */
            void setRoot(basicTreeNodePtr root)
            {
                if (_Root) delete (_Root);
                _Root = root;
            }

            /**
            *	Получить корень дерева непосредственно
            */
            basicTreeNodePtr getRoot() 
            {
                return _Root;
            }

            /**
            *	Получить корень дерева
            */
            bt_iterator begin ()		
            {	
                return ( bt_iterator ( *this, _Root) );		
            }

            /**
            *	Конец дерева
            */
            bt_iterator end ()			
            {	
                return ( bt_iterator ( *this, NULL ) );		
            }

            /**
            *	Удалить дерево
            */
            void clear()
            {
                erase(getRoot());
                if (_Root) delete _Root;
                _Root = NULL;
            }

            protected:

            /**
            * Удалить рекурсивно начиная с _node
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
