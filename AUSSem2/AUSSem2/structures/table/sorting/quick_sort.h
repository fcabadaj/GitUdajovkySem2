#pragma once

#include "sort.h"
#include "../unsorted_sequence_table.h"
#include "../../../Kriterium.h"

namespace structures
{

	/// <summary> Triedenie Quick sort. </summary>
	/// <typeparam name = "K"> Kluc prvkov v tabulke. </typepram>
	/// <typeparam name = "T"> Typ dat ukladanych v tabulke. </typepram>
	template <typename K, typename T>
	class QuickSort : public Sort<K, T>
	{
	public:
		/// <summary> Utriedi tabulku triedenim Quick sort. </summary>
		/// <param name = "table"> NonortedSequenceTable, ktoru ma utriedit. </param>
		void sort(UnsortedSequenceTable<K, T>& table) override;
		template< typename T2>
		void sorth(UnsortedSequenceTable<K, T*>& table, Kriterium<T2,T> &kriterium, bool descending);
		template <typename T2>
		void quick(int min, int max, UnsortedSequenceTable<K, T*>& table, Kriterium<T2, T>& kriterium);
		template <typename T2>
		void quickDesc(int min, int max, UnsortedSequenceTable<K, T*>& table, Kriterium<T2, T>& kriterium);
	};

	template<typename K, typename T>
	inline void QuickSort<K, T>::sort(UnsortedSequenceTable<K, T>& table)
	{		
	}

	template <typename K, typename T>
	template <typename T2>
	inline void QuickSort<K, T>::sorth(UnsortedSequenceTable<K, T*>& table, Kriterium<T2, T> &kriterium, bool descending)
	{
		if (table.size() != 0)
		{
			if (descending)
			{
				quickDesc(0, table.size() - 1, table, kriterium);
			}
			else
			{
				quick(0, table.size() - 1, table, kriterium);
			}
			
		}
		else
		{
			cout << "======================================================= \n";
			cout << "Neboli najdene ziadne zaznamy na usporiadanie!! \n";
		}
	}
	template<typename K, typename T>
	template <typename T2>
	inline void QuickSort<K, T>::quick(int min, int max, UnsortedSequenceTable<K, T*>& table, Kriterium<T2, T> &kriterium)
	{
		TableItem<K, T*> pivot = table.getItemAtIndex((min + max) / 2);
		
		int lavy = min;
		int pravy = max;

		do
		{
			while (kriterium.evaluate(*table.getItemAtIndex(lavy).accessData()) < kriterium.evaluate(*pivot.accessData()))
				lavy++;

			while (kriterium.evaluate(*table.getItemAtIndex(pravy).accessData())  > kriterium.evaluate(*pivot.accessData()))
				pravy--;

			if (lavy <= pravy)
			{
				table.swap(lavy, pravy);
				lavy++;
				pravy--;
			}


		} while (lavy <= pravy);

		if (min < pravy)
			quick(min, pravy, table, kriterium);

		if (lavy < max)
			quick(lavy, max, table, kriterium);
	}

	template<typename K, typename T>
	template <typename T2>
	inline void QuickSort<K, T>::quickDesc(int min, int max, UnsortedSequenceTable<K, T*>& table, Kriterium<T2, T>& kriterium)
	{
		TableItem<K, T*> pivot = table.getItemAtIndex((min + max) / 2);

		int lavy = min;
		int pravy = max;

		do
		{
			while (kriterium.evaluate(*table.getItemAtIndex(lavy).accessData()) > kriterium.evaluate(*pivot.accessData()))
				lavy++;

			while (kriterium.evaluate(*table.getItemAtIndex(pravy).accessData()) < kriterium.evaluate(*pivot.accessData()))
				pravy--;

			if (lavy <= pravy)
			{
				table.swap(lavy, pravy);
				lavy++;
				pravy--;
			}


		} while (lavy <= pravy);

		if (min < pravy)
			quickDesc(min, pravy, table, kriterium);

		if (lavy < max)
			quickDesc(lavy, max, table, kriterium);
	}
}