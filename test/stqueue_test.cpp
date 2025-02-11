
typedef struct data
{
	int i;
	//STQUEUE_ENTRY(data);
	data* next;
}DATA, *PDATA;


int main()
{
	STQUEUE<DATA>* que = new STQUEUE<DATA>;
	PDATA ptr_ = NULL;
	for (int i = 0; i < 3; ++i)
	{
		PDATA dat = new DATA;
		dat->i = i + 1;
		if (i >= 6)
			que->STQUEUE_INSERT_TAIL(dat);
		else
			que->STQUEUE_INSERT_HEAD(dat);
		
		if (i == 1)
			ptr_ = dat;
	}

	PDATA dat_after = new DATA;
	dat_after->i = 10;
	que->STQUEUE_INSERT_AFTER(dat_after, ptr_);

	
	PDATA dat = new DATA;
	VOID* f = dat;
	STQUEUE_FOREACH(dat, que)
	{
		std::cout << dat->i << std::endl;
	}

	std::cout << "\n\n";
	que->STQUEUE_DELETE_HEAD();	

	
	std::cout << "\nnext\n";
	for (dat = (PDATA)que->STQUEUE_HEAD(); dat; dat = que->STQUEUE_NEXT(dat))
	{
		std::cout << dat->i << std::endl;
	}


	STQUEUE<DATA>* qu = new STQUEUE<DATA>;
	for (int i = 100; i < 105; ++i)
	{
		PDATA datq = new DATA;
		datq->i = i;
		qu->STQUEUE_INSERT_HEAD(datq);
	}

	std::cout << "to conct\n";
	STQUEUE_FOREACH(dat, qu)
	{
		std::cout << dat->i << std::endl;
	}
	//que->STQUEUE_CONCAT(qu);
	que->operator=(qu);
	std::cout << "after conct\n";
	STQUEUE_FOREACH(dat, que)
	{
		std::cout << dat->i << std::endl;
	}
	

	free(f);
	delete que;
	_CrtDumpMemoryLeaks();
	return EXIT_SUCCESS;
}
