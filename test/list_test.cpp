#define _CRTDBG_MAP_ALLOC
#include <crtdbg.h>
#define DBG_NEW new( _NORMAL_BLOCK , __FILE__ , __LINE__ )
#define newDBG_NEW


#include <iostream>
#include "structures.h"


typedef struct data
{
	int i;
	/*struct
	{
		data* next;
		data* prev;
	};*/
	LIST_ENTRY(data);
}DATA, *PDATA;


int main()
{

	LIST<DATA>* list = new LIST<DATA>();

	PDATA sp = NULL;
	for (int i = 0; i < 4; ++i)
	{
		PDATA dat = new DATA;
		dat->i = i + 1;
		list->LIST_INSERT_HEAD(dat);

		if (i == 1)
			sp = dat;
	}

	list->LIST_DELETE_HEAD();


	PDATA d_tail = new DATA;
	d_tail->i = 10;
	list->LIST_INSERT_TAIL(d_tail);
	PDATA dat_a = new DATA;
	dat_a->i = 20;	
	list->LIST_INSERT_AFTER(sp, dat_a);
	//list->LIST_INSERT_BEFORE(sp, dat_a);


	PDATA dat = NULL;
	for (dat = list->ptr; dat; dat = dat->next)
	{
		std::cout << dat->i << std::endl;
	}
	std::cout << "\n";
	list->LIST_DELETE_TAIL();
	std::cout << "deleted elm: " << sp->i << std::endl;
	list->LIST_DELETE_ELM(sp);
	for (dat = list->tptr; dat; dat = dat->prev)
	{
		std::cout << dat->i << std::endl;
	}


	PDATA find = list->LIST_FIND_ELM(&DATA::i, 3);
	if (find != NULL)
		std::cout << "FIND ELM! \t" << find->i << std::endl;


	std::cout << "\nLIST_FOR\n";
	LIST_FOREACH(find, list)
	{
		std::cout << find->i << std::endl;
	}
	std::cout << "\nREV_LIST_FOR\n";
	REV_LIST_FOREACH(find, list)
	{
		std::cout << find->i << std::endl;
	}


	LIST<DATA>* list_concat = new LIST<DATA>;

	for (int i = 100; i <= 105; ++i)
	{
		PDATA dat_c = new DATA;
		dat_c->i = i;
		list_concat->LIST_INSERT_HEAD(dat_c);
	}

	//list->LIST_CONCAT_HEAD(list_concat);
	//list->LIST_CONCAT_TAIL(list_concat);
	*list = *list_concat;


	PDATA datc = NULL;	
	std::cout << "\nLIST CONCAT\n";
	LIST_FOREACH(datc, list)
	{
		std::cout << datc->i << std::endl;
	}
	std::cout << "\nREV LIST CONCAT\n";
	REV_LIST_FOREACH(datc, list)
	{
		std::cout << datc->i << std::endl;
	}

	delete list;
	_CrtDumpMemoryLeaks();
	return EXIT_SUCCESS;
}
