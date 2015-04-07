///////////////////////////////////////////////////////////
//  basicTemplateList.h
//  –еализаци€	Class basicTemplateList
//  —оздано:    15-фев-2010 22:56:19
//  јвтор:		Dr_Freeman
///////////////////////////////////////////////////////////

#if !defined(EA_43B0BD94_AD58_44a3_9502_E85E86B3FB6E__INCLUDED_)
#define EA_43B0BD94_AD58_44a3_9502_E85E86B3FB6E__INCLUDED_

namespace Gepard
{
	namespace General
	{
		/**
		 *  Ѕазовый класс дл€ списка и массива
		 * (basicArray и basicList)
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
			 * „исло колонок массива (только если isList=false)
			 */
			unsigned int Columns;
			/**
			 * явл€етс€ ли данный массив одномерным
			 * »наче - эмул€ци€ двухмерного массива
			 */
			bool is_List;
			/**
			 * „исло строк двумерного массива (только если isList=false)
			 */
			unsigned int Rows;

		};

	}

}
#endif // !defined(EA_43B0BD94_AD58_44a3_9502_E85E86B3FB6E__INCLUDED_)
