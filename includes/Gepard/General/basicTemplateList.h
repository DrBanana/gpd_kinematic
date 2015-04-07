///////////////////////////////////////////////////////////
//  basicTemplateList.h
//  ����������	Class basicTemplateList
//  �������:    15-���-2010 22:56:19
//  �����:		Dr_Freeman
///////////////////////////////////////////////////////////

#if !defined(EA_43B0BD94_AD58_44a3_9502_E85E86B3FB6E__INCLUDED_)
#define EA_43B0BD94_AD58_44a3_9502_E85E86B3FB6E__INCLUDED_

namespace Gepard
{
	namespace General
	{
		/**
		 *  ������� ����� ��� ������ � �������
		 * (basicArray � basicList)
		 */
		class basicTemplateList
		{

		public:
			basicTemplateList();
			~basicTemplateList();
			void createArray(unsigned int _columns, unsigned int _rows);
			void createList();
			int getColumns();
			int getRows();
			bool isList();

		protected:
			/**
			 * ����� ������� ������� (������ ���� isList=false)
			 */
			unsigned int Columns;
			/**
			 * �������� �� ������ ������ ����������
			 * ����� - �������� ����������� �������
			 */
			bool is_List;
			/**
			 * ����� ����� ���������� ������� (������ ���� isList=false)
			 */
			unsigned int Rows;

		};

	}

}
#endif // !defined(EA_43B0BD94_AD58_44a3_9502_E85E86B3FB6E__INCLUDED_)
