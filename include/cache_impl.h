#ifndef CACHE_IMPL_H
#define	CACHE_IMPL_H


#ifdef	__cplusplus
extern "C" {
#endif


#include "index_impl.h"
#include "defn_impl.h"
#include "cache.h"


struct Cache_Entry{

	Word word;	//word 

	EntryList edit_results[4];    	//editentrylists with dist 0,1,2,3
								
	
	Cache_Entry*  	next;     			//next cache entry							
	Cache_Entry* 		prev;     			//previous cache entry

	Cache_Entry*  	hash_next;     	//next hash cache entry							
	Cache_Entry* 		hash_prev;     	//previous hash cache entry


};


struct Cache_Queue{

	Cache_Entry*	head;         //head of cache queue  
	Cache_Entry*	tail;         //tail of cache queue
	int	num_of_entries;  	

};



struct Cache{

	Cache_Entry** HashTable;		//cache hash table
	Cache_Queue* 	queue;				//cache queue

	unsigned int queue_size;				//size of cache
	unsigned int hash_size;					//size of hash table

	int searches;
	int hits;

};

#ifdef	__cplusplus
}
#endif

#endif	/* CACHE_IMPL_H */