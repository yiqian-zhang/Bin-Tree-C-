#ifndef __SQ_LIST_H__
#define __SQ_LIST_H__

template <class ElemType>
class SeqList 
{
protected:
	int length;					
	int maxLength;				
	ElemType *elems;		

public:
	SeqList(int size = DEFAULT_SIZE);	
	SeqList(ElemType v[], int n, int size = DEFAULT_SIZE);	
	virtual ~SeqList();			
	int GetLength() const;			 
	bool IsEmpty() const;		
	void Clear();			
	void Traverse(void (*Visit)(const ElemType &)) const;	
	int LocateElem(const ElemType &e) const;	
	Status GetElem(int i, ElemType &e) const;	
	Status SetElem(int i, const ElemType &e);	
	Status DeleteElem(int i, ElemType &e);     	
	Status InsertElem(int i, const ElemType &e); 
 	Status InsertElem(const ElemType &e);       
	SeqList(const SeqList<ElemType> &sa);      
	SeqList<ElemType> &operator =(const SeqList<ElemType> &sa);
	int Max() const;
    int Min() const;
    void OrderElem();
};


template <class ElemType>
void SeqList<ElemType>::OrderElem()
{
     for(int i=0;i<length-1;i++)
       for(int j=0;j<length-1-i;j++)
        if(elems[j]>elems[j+1])
        {
           ElemType t=elems[j];
           elems[j]=elems[j+1];
           elems[j+1]=t;
        }  
}


template <class ElemType>
int SeqList<ElemType>::Max() const
{
    int temps=0;
    for(int i =1;i<length;i++){
            if(elems[i]>elems[temps]) temps=i;     
    }
    ElemType max=elems[temps];
    return temps;
}
   
   
template <class ElemType>
int SeqList<ElemType>::Min() const
{
    int temps=0;
    for(int i =1;i<length;i++){
            if(elems[i]<elems[temps]) temps=i;     
    }
    ElemType min=elems[temps];
    return temps;
}          

template <class ElemType>
SeqList<ElemType>::SeqList(int size)
{
	elems = new ElemType[size];		    
	assert(elems);                      
	maxLength = size;					
	length = 0;							
}

template <class ElemType>
SeqList<ElemType>::SeqList(ElemType v[], int n, int size)
{
	elems = new ElemType[size];		   
	assert(elems);                     
	maxLength = size;				
	length = n;						
	for (int i = 0; i < length; i++)
		elems[i] = v[i]; 
}
 
template <class ElemType>
SeqList<ElemType>::~SeqList()
{
	delete []elems;					
}

template <class ElemType>
int SeqList<ElemType>::GetLength() const
{
	return length;
}

template <class ElemType>
bool SeqList<ElemType>::IsEmpty() const
{
	return length == 0;
}

template <class ElemType>
void SeqList<ElemType>::Clear()
{
	length = 0;
}

template <class ElemType>
void SeqList<ElemType>::Traverse(void (*visit)(const ElemType &)) const
{
	for (int i = 0; i < length; i++)
		(*visit)(elems[i]);
}

template <class ElemType>
int SeqList<ElemType>::LocateElem(const ElemType &e) const
{
	int i = 0;
    while (i < length && elems[i] != e)
         i++;	
    return i < length ? i+1 : 0;
}

template <class ElemType>
Status SeqList<ElemType>::GetElem(int i, ElemType &e) const
{
	if(i < 1 || i > length)
		return NOT_PRESENT;	
	else	{
		e = elems[i - 1];
		return ENTRY_FOUND;	
	}
}

template <class ElemType>
Status SeqList<ElemType>::SetElem(int i, const ElemType &e)
{
	if (i < 1 || i > length)
		return RANGE_ERROR;
	else	{
		elems[i - 1] = e;
		return SUCCESS;	
	}
}

template <class ElemType>
Status SeqList<ElemType>::DeleteElem(int i, ElemType &e)
{
	if (i < 1 || i > length)		
		return RANGE_ERROR;      
	else	{
		e = elems[i - 1];	    
		for (int j = i; j < length; j++)
			elems[j-1] = elems[j]; 
		length--;			
		return SUCCESS;	       
	}
}

/*template <class ElemType>
Status SeqList<ElemType>::InsertElem(int i, const ElemType &e)
{
	if (length == maxLength)
		return OVER_FLOW;	            	
	else if (i < 1 || i > length + 1)		
		return RANGE_ERROR;
	else	{
		for (int j = length; j >= i; j--)  
			elems[j] = elems[j - 1]; 
		elems[i - 1] = e;	               	
   		length++;				           
     	return SUCCESS;			           
	}
}
*/
template <class ElemType>
Status SeqList<ElemType>::InsertElem(const ElemType &e)
{
	if (length==maxLength)		
		return OVER_FLOW;	
	else	{
		elems[length] = e;	    
   		length++;
        //elems.OrderElem();				
     	return SUCCESS;			
	}
	/*if(e>=elems[length-1]) 
            { 
               elems[length]=e; length++; return SUCCESS;
            }
       else 
       {
                     for(int i=0; i<length; i++)
                     {
                          if(e<elems[i])
                          {	//23467    5
                             for (int j = length; j > i; j--)  
		 	                    elems[j] = elems[j - 1]; 
		                     elems[i] = e;	               
                             length++;				           
     	                     return SUCCESS;	
                          }
                     }
       }*/
}

template <class ElemType>
SeqList<ElemType>::SeqList(const SeqList<ElemType> &sa)
{
	int saLength = sa.GetLength();	
	ElemType e;

	maxLength = sa.maxLength;		
	elems = new ElemType[maxLength];
	assert(elems);                  
	length = 0;					    

	for (int i = 1; i <= saLength; i++)	{
		sa.getElem(i, e);		    
		insertElem(e);			    
	}
}

template <class ElemType>
SeqList<ElemType> &SeqList<ElemType>::operator =(const SeqList<ElemType> &sa)
{
	if (&sa != this)	{
		int saLength = sa.GetLength();	
		ElemType e;

        maxLength = sa.maxLength;		
        delete []elems;                
        elems = new ElemType[maxLength];
	    assert(elems);                  
        length = 0;						
        for (int i = 1; i <= saLength; i++)	{
			sa.getElem(i, e);	        
			insert(e);		            
		}
	}
	return *this;
}

#endif
