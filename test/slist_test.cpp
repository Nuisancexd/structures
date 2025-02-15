#define _CRTDBG_MAP_ALLOC
#include <crtdbg.h>
#define DBG_NEW new( _NORMAL_BLOCK , __FILE__ , __LINE__ )
#define newDBG_NEW


#include <iostream>
#include "structures.h"





typedef struct data
{
	int i;
	//data* entries;
	SLIST_ENTRY(data);
}DATA, *PDATA;


int main()
{
	SLIST<DATA>* list = new SLIST<DATA>;
	PDATA ptr = NULL;
	for (int i = 0; i < 6; ++i)
	{
		PDATA dat = new DATA;
		dat->i = i + 1;
		
		list->SLIST_INSERT_HEAD(dat);
		if (i == 2)
			ptr = dat;
	}

	PDATA dat = (PDATA)list->SLIST_HEAD();
	list->SLIST_DELETE_HEAD(dat);
	dat = (PDATA)list->SLIST_HEAD();
	list->SLIST_DELETE_HEAD(dat);

	list->SLIST_REMOVE_ELM(ptr);

	for (dat = (PDATA)list->SLIST_HEAD(); dat; dat = dat->entries)
	{
		std::cout << dat->i << std::endl;
	}

	PDATA find = list->LIST_FIND_ELM(&DATA::i, 4);
	if (find != NULL)
		std::cout << "FIND ELM! \t" << find->i << std::endl;

	SLIST<DATA>* list_concat = new SLIST<DATA>;
	for (int i = 100; i < 105; ++i)
	{
		PDATA dat = new DATA;
		dat->i = i;
		list_concat->SLIST_INSERT_HEAD(dat);
	}

	//*list = *list_concat;
	list->SLIST_CONCAT(list_concat);

	PDATA dat_ = NULL;	
	std::cout << "\nCONCAT\n";
	SLIST_FOREACH(dat_, list)
	{
		std::cout << dat_->i << std::endl;
	}

	
	delete list;

	_CrtDumpMemoryLeaks();
	return EXIT_SUCCESS;

}



