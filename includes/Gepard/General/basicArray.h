///////////////////////////////////////////////////////////
//  basicArray.h
//  ����������	Class basicArray
//  �������:	20-���-2012 12:33:14
//  �����:		Dr_Freeman
///////////////////////////////////////////////////////////

#if !defined(EA_0EDFAABC_CCB3_4060_AC95_245F36F37DBA__INCLUDED_)
#define EA_0EDFAABC_CCB3_4060_AC95_245F36F37DBA__INCLUDED_

#include "basicTemplateList.h"
#include "std_inc.h"

namespace Gepard
{
    namespace General
    {
        /** 
         * �����-������� ��� std::vector - ������ ���������
         */
        template <class T>
        class basicArray : public basicTemplateList
        {
        public:
            //-------------------------------------------------------------
            basicArray() 
                : stat_array_counter(0), elements_counter(0)
            {
                createList();
            }
            //-------------------------------------------------------------
            basicArray(unsigned int columns, unsigned int rows)
                : stat_array_counter(0), elements_counter(0)
            {
                createArray(columns,rows);
            }
            //-------------------------------------------------------------
            ~basicArray()
            {
                clear();
            }
            //-------------------------------------------------------------
            /**
            * �������� ������� � ������. ������ ��� isList=true
            */
            T* addElement(T element)
            {
                if (isList()) Elements.push_back(element);
                std::vector<T>::reverse_iterator rev_itr = Elements.rbegin();
                return &(*rev_itr);
            }
            //-------------------------------------------------------------

            /**
            * �������� ������
            */
            void clear()
            {
                Elements.clear();
            }
            //-------------------------------------------------------------

            /**
            * ������� ������� �� ������� (������ ��� isList = true)
            */
            void deleteElement(unsigned int index)
            {
                if (!isList()) return;

                std::vector<T>::iterator itr;
                int iter_index=0;
                for (itr = Elements.begin(); itr!=Elements.end(); ++itr)
                {
                    if (iter_index==index) {Elements.erase(itr); return;}
                    iter_index++;
                }//for				
            }
            //-------------------------------------------------------------

            /**
            * ������� ������� �� ������. ������ ��� isList=true
            */
            void deleteElement(const T &element)
            {
                if (isList()) Elements.remove(element);				
            }
            //-------------------------------------------------------------

            /**
            * �������� ��������� �� ������� �� ���� ��������. ���� isList=true, ������ ��������
            * ������������
            */
            T* getAt(unsigned int column, unsigned int row)
            {
                if (isList()) return getAt(column);
                unsigned int retInt = getIndex(column,row);
                return getAt(retInt);		
            }
            //-------------------------------------------------------------

            /**
            * �������� ��������� �� ������� �� �������
            */
            T *getAt(unsigned int index)
            {	
                if (index>=Elements.size()) return &(*Elements.begin());
                return &Elements[index];
            }
            //-------------------------------------------------------------

            /**
             *  �������� ������� �� �������
             */
            T valAt(unsigned int index)
            {
                return *getAt(index);
            }

            //-------------------------------------------------------------

            /**
             *  �������� ������� �� ���� ��������. ���� isList=true, ������ ��������
             *  ������������
             */
            T valAt(unsigned int column, unsigned int row)
            {
                return *getAt(column, row);
            }

            //-------------------------------------------------------------
            /**
            * �������� ����� ���������
            */
            unsigned int getCount()
            {
                return Elements.size();
            }
            //-------------------------------------------------------------
            
            /**
            * �������� ������� �� �������
            */
            T *operator[](unsigned int index)
            {
                return &Elements[index];
            }
             //-------------------------------------------------------------
            /**
            * �������� �������
            */
            T *operator<<(T &element)
            {
                return addElement(element);
            }
            //-------------------------------------------------------------
            /**
            * �������� ������ ���������
            */
            void operator<<(basicArray<T> &_array)
            {
                addElements(_array);
            }
            //-------------------------------------------------------------

            /**
            * �������� ������� � ������� - ������ ��� isArrayList=true
            */
            void setAt(unsigned int column, unsigned int row, T &element)
            {
                if (isList()) return;
                int retInt = getIndex(column,row);		
                Elements[retInt] = element;						
            }
            //-------------------------------------------------------------

            /**
             *	�������� ������� � ������ �� �������
             *	�� ������ �������������� �������� (=) - (���� �����)
             */
            void setAt(int index, T &element)
            {				
                Elements[index] = element;
            }
            //-------------------------------------------------------------

            /**
            *	�������� ������� - ������ ��� isArrayList=true
            */
            void addColumn(std::list<T> &column)
            {
                if (isList()) return;
                std::vector<T> tp_vec(column.begin(),column.end());
                addColumn(tp_vec);
            }
            //-------------------------------------------------------------

            /**
            *	�������� ������� - ������ ��� isArrayList=true
            */
            void addColumn(std::vector<T> &column)
            {
                if (isList()) return;

                    if (Rows == 0) {
                        Rows = column.size();
                        std::vector<T>::iterator itr;
                        for (itr=column.begin(); itr!=column.end(); ++itr)
                        {
                            Elements.push_back(*itr);
                        }
                        Columns++;
                        return;
                    }

                if (column.size()>Rows) return;

                std::vector<T>::iterator row_itr=column.begin();
                std::vector<T>::iterator elem_itr;

                int counter =0;
                for (elem_itr=Elements.begin(); elem_itr!=Elements.end(); ++elem_itr)
                {
                    if (counter==Columns) {
                        Elements.insert(elem_itr,*row_itr);
                        ++row_itr;
                        counter=0;
                    }
                    counter++;
                }
                Elements.push_back(*row_itr);

                Columns++;
            }
            //-------------------------------------------------------------

            /**
            *	�������� ������ - ������ ��� isArrayList=true
            */
            void addRow(std::list<T> &row)
            {
                if (isList()) return;
                std::vector<T> tp_vec(row.begin(),row.end());
                addRow(tp_vec);
            }

            //-------------------------------------------------------------

            /**
            *	�������� ������ - ������ ��� isArrayList=true
            */
            void addRow(std::vector<T> &row)
            {
                if (isList()) return;
                if (Columns == 0) Columns = row.size();
                if (row.size()>Columns) return;

                std::vector<T>::iterator itr;
                for (itr=row.begin(); itr!=row.end(); ++itr)
                {
                    Elements.push_back(*itr);
                }
                Rows++;
            }

            //-------------------------------------------------------------

            /**
            *  �������� � �������� ������ ��� ����
            */
            void addElements(basicArray<T> _vec)
            {
                std::vector<T>::iterator itr;
                for (itr = _vec.Elements.begin(); itr!=_vec.Elements.end(); ++itr)
                {
                    Elements.push_back(*itr);
                }
            }

            //-------------------------------------------------------------

            /**
             *	���������� �������� �� ������ - ����� ����� ���������� get_next
             */
            void set_start() 
            {	
                n_iterator = Elements.begin();	
                elements_counter = -1;
            }

            //-------------------------------------------------------------

            /**
             *	���������� �������� � ����� - ����� ����� ���������� get_prev
             */
            void set_end() 
            {	
                n_iterator = Elements.end();	
                elements_counter = Elements.size();
            }

            //-------------------------------------------------------------

            /**
             *	�������� ��������� �������. NULL - ������ ��� ���������
             */
            T* get_next()
            {
                if (getCount()==0) return NULL;
                if (n_iterator == Elements.end()) return NULL;
                T* cur_element_ptr = &(*n_iterator); ++n_iterator;
                elements_counter++;
                return cur_element_ptr;
            }
            //-------------------------------------------------------------

            /**
             *	�������� ���������� �������. NULL - ������ ��� ���������
             */
            T* get_prev()
            {
                if (getCount()==0) return NULL;
                if (elements_counter == 0) return NULL;
                --n_iterator; elements_counter--;
                T* cur_element_ptr = &(*n_iterator); 				
                return cur_element_ptr;
            }
            //-------------------------------------------------------------

            /**
             *	�������� �������� ������� �������� ������������� ��������,
             *	��� set_stert()/get_next()
             */
            unsigned int get_current_index()
            {
                return elements_counter;
            }
            //-------------------------------------------------------------

            /**
             *	���������� ������ �������
             */
            void set_size(unsigned int newSize)
            {
                Elements.resize(newSize);
                stat_array_start();
            }
            //-------------------------------------------------------------


            /**
             *  ������� ��������� "�����������" ������
             *  - ����� ������ set_size( columns * rows );
             *  - ��������� � ������� setAt()
             */
            void stat_create_array( unsigned int columns, unsigned int rows )
            {
                createArray(columns,rows);
                set_size(columns*rows);
            }

            //-------------------------------------------------------------

            /**
             *	���������� ������� ������� ����������� ��������� � 0
             *  - ��� ����������� �������� (����� set_size)
             */
            void stat_array_start() {stat_array_counter = 0;}
            //-------------------------------------------------------------

            /**
             *	�������� ������� � ������������ ������� (����� set_size)
             *  - �.�., �������� ������� � ������� � ������������� ��������
             *	(stat_array_counter)
             *	�� ������ �������������� �������� (=) - ���� ����.
             */
            void stat_array_add(T &_element)
            {
                if (stat_array_counter>=Elements.size()) 
                {
                    throw std::logic_error("<basicArray::stat_array_add> �������� ���������� ��������� ������������ �������.");
                };
                Elements[stat_array_counter] = _element;
                stat_array_counter++;
            }
            //-------------------------------------------------------------

            /**
             *  �������� �������� �������� ������������ �������
             */
            unsigned int stat_get_counter()  { return stat_array_counter;  }

            //-------------------------------------------------------------
            /**
             *	�������� ������ �������
             */
            (typename std::vector<T>::iterator) std_begin()
            {
                return Elements.begin();
            }

             //-------------------------------------------------------------

            /**
             *	�������� ����� �������
             */
            (typename std::vector<T>::iterator) std_end()
            {
                return Elements.end();
            }
            //-------------------------------------------------------------

            /**
             *  �������� ��������� �������
             */
            T* getLastElement()
            {
                return &(*Elements.rbegin());
            }

            /**
             *	��������� ������ � �����
             */
            void SaveToStream(std::ostream &_stream)
            {
                char _isList = 0;
                if (isList()) _isList = 1;

                _stream.write((char *)&_isList,sizeof(char));
                _stream.write((char *)&Columns,sizeof(unsigned int));
                _stream.write((char *)&Rows,sizeof(unsigned int));

                unsigned int _list_count = getCount();
                _stream.write((char *)&_list_count,sizeof(unsigned int));

                std::vector<T>::iterator itr;
                for (itr = Elements.begin(); itr!=Elements.end(); ++itr)
                {
                    _stream.write((char *)&(*itr),sizeof(T));
                }

            }

            /**
             *	��������� ������ � �����
             */
            void ReadFromStream(std::istream &_stream)
            {
                char _isList = 0;			

                _stream.read((char *)&_isList,sizeof(char));
                _stream.read((char *)&Columns,sizeof(unsigned int));
                _stream.read((char *)&Rows,sizeof(unsigned int));

                if (_isList==1) is_List = false; else is_List = true;
    
                unsigned int _list_count;
                _stream.read((char *)&_list_count,sizeof(unsigned int));

                for (unsigned int i =0; i<_list_count; i++)
                {
                    T _element;
                    _stream.read((char *)&_element,sizeof(T));
                    Elements.push_back(_element);
                }
            }

            /**
             *  �������� ����������
             */
            basicArray<T>& operator=(const basicArray<T> &_array)
            {
                Elements.clear();
                Elements = _array.Elements;
                Columns  = _array.Columns;
                Rows     = _array.Rows;
                is_List  = _array.is_List;
                return *this;
            }


        public:
            /**
            * ������ ���������
            */
            std::vector<T> Elements;
            /**
             * ������ �������� ��������
             */			
            typedef typename std::vector<T>::iterator _ITERATOR;

        private:
            //-------------------------------------------------------------

            /**
            *	�������� ������ � ������ Elements �� Row � Col
            */
            unsigned int getIndex(unsigned int column, unsigned int row)
            {
                unsigned int retInt = (row*getColumns()+column);
                return retInt;

            }
            //-------------------------------------------------------------

            /**
             *	��������, ��� ���������� ������� set_start()/get_next()
             */
            typename std::vector<T>::iterator n_iterator;

            /**
             *	������� ����������� ���������,
             *  ��� ���������� ������� stat_array_add()/stat_array_start()
             */
            unsigned int stat_array_counter;

            /**
             *	������� ������������� ��������,
             *	��� set_start()/get_next()
             */
            unsigned int elements_counter;
        };

    }

}
#endif // !defined(EA_0EDFAABC_CCB3_4060_AC95_245F36F37DBA__INCLUDED_)
