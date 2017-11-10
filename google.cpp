///*
// * google.cpp
// *
// *  Created on: Oct 18, 2017
// *      Author: David
// */
//
//#include "query_result.h"
//#include "stopword.h"
//#include "word_tokenizer.h"
//#include "document_indexer.h"
//#include "index_document.h"
//#include "sentence_token.h"
//
//int main()
//{
//	index_document *doc1 = new index_document("file1.txt");
//    index_document *doc0 = new index_document("file2.txt");
//    index_document *doc2 = new index_document("file3.txt");
//	doc1->content();
//	document_indexer *idx2 = new document_indexer();
//	(*idx2)>>*doc0;
//	(*idx2)>>*doc1;
//	(*idx2)>>*doc0;
//	(*idx2)>>*doc2;
//	int i = 1;
//    index_document *dictionary = new index_document();
//    index_document *doc = new index_document();
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
//	dictionary->sorting();
//	dictionary->duplicateRemove();
//    index_document *docStop = new index_document ("stop.txt");
////	indexer idxStop = indexer();
////	idxStop >> *docStop;
//    index_document *stopDict = new index_document ();
//	stopDict->compare(*dictionary);
//	stopDict->sorting();
//	stopDict->duplicateRemove();
//	idx2->dftfFinder(*stopDict);
//	idx2->normalize();
//	idx2->indexDictionary(*stopDict);
//	vector<query_result> ranks;
//	ranks = idx2->query("you figure out token dog circuit Tested products using checklists",5);
//	sort(ranks.begin(),ranks.end(),query_result::scorecomp);
//	for(unsigned int i =0 ; i<ranks.size(); ++i){
//	ranks[i].info();}
//
//}
