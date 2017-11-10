///*
// * indexerdriver.cpp
// *
// *  Created on: Nov 9, 2017
// *      Author: David
// */
//
//#include "document_indexer.h"
//#include "index_document.h"
//
//int main()
//{
//	index_document *doc1 = new index_document("file2.txt");
//
//	index_document *doc0 = new index_document("file1.txt");
//	index_document *doc2 = new index_document("file3.txt");
//
//	document_indexer *idx2 = new document_indexer();
//	(*idx2)>>*doc0;
//	(*idx2)>>*doc1;
//	(*idx2)>>*doc0;
//	(*idx2)>>*doc2;
//
//
//	index_document *dictionary = new index_document();
//	index_document *doc = new index_document();
//
//	int i = 1;
//	*doc = (*idx2)[i];
//	dictionary->toCreateDictionary(*doc);
//	i = 0;
//	*doc = (*idx2)[i];
//	dictionary->toCreateDictionary(*doc);
//	i=2;
//	*doc = (*idx2)[i];
//	dictionary->toCreateDictionary(*doc);
//	i=3;
//	*doc = (*idx2)[i];
//	dictionary->toCreateDictionary(*doc);
//
//	dictionary->sorting();
//	dictionary->duplicateRemove();
//
//
//	index_document *docStop = new index_document ("stop.txt");
//
//	index_document *stopDict = new index_document ();
//	stopDict->compare(*dictionary);
//	stopDict->sorting();
//
//	idx2->dftfFinder(*stopDict);
//	idx2->normalize();
//	idx2->indexDictionary(*stopDict);
//
//	idx2->print(*stopDict);
//}


