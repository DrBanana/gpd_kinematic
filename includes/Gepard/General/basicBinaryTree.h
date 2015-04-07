///////////////////////////////////////////////////////////
//  basicBinaryTree.h
//  ���������� Class basicBinaryTree
//  �������:      08-���-2012 21:09:31
//  �����: Dr_Freeman
///////////////////////////////////////////////////////////

#if !defined(EA_99070037_295C_4d1c_9D5B_20F822A19CF6__INCLUDED_)
#define EA_99070037_295C_4d1c_9D5B_20F822A19CF6__INCLUDED_

#include "General\basicObject.h"

namespace Gepard
{
	namespace General
	{
		/**
		 * ����� ��������� ������
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
			 * ������ ������? � ������������ ��������� isTreeNull=true
			 */
			bool isTreeNull;
			/**
			 * ����� ����� ������
			 */
			T* left;
			/**
			 * �������� ����� ������
			 */
			T* parent;
			/**
			 * ������ ����� ������
			 */
			T* right;

		};

	}

}
#endif // !defined(EA_99070037_295C_4d1c_9D5B_20F822A19CF6__INCLUDED_)
