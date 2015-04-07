///////////////////////////////////////////////////////////
//  basicBinaryTree.h
//  Реализация Class basicBinaryTree
//  Создано:      08-ноя-2012 21:09:31
//  Автор: Dr_Freeman
///////////////////////////////////////////////////////////

#if !defined(EA_99070037_295C_4d1c_9D5B_20F822A19CF6__INCLUDED_)
#define EA_99070037_295C_4d1c_9D5B_20F822A19CF6__INCLUDED_

#include "General\basicObject.h"

namespace Gepard
{
	namespace General
	{
		/**
		 * класс двоичного дерева
		 */
		template<class T>
		class basicBinaryTree : public Gepard::General::basicObject
		{

		public:
			basicBinaryTree(){

			}
			~basicBinaryTree(){

			}
			void addLeft(const T& LeftNode){

			}
			void addRight(const T& NodeRight){

			}
			T* getLeft(){

				return left;
			}
			T* getParent(){

				return  NULL;
			}
			T* getRight(){

				return right;
			}
			bool isNull(){

				return false;
			}

		private:
			/**
			 * Пустое дерево? В конструкторе прописать isTreeNull=true
			 */
			bool isTreeNull;
			/**
			 * левая ветка дерева
			 */
			T* left;
			/**
			 * корневая ветка дерева
			 */
			T* parent;
			/**
			 * правая ветка дерева
			 */
			T* right;

		};

	}

}
#endif // !defined(EA_99070037_295C_4d1c_9D5B_20F822A19CF6__INCLUDED_)
