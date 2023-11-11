void selection_sort()
{
	struct node *p,*q,*s,*r,*temp;
	if(head==NULL)
	{
		printf("List is empty\n");
		return;
	}
	if(head->link==NULL)
		return;
	for(p=r=head;p->link!=NULL;r=p,p=p->link)
	{

		for(q=s=p->link;q!=NULL;s=q,q=q->link)
		{
			if(p->data > q->data)
			{
				if(p->link!=q)
				{

					temp=p->link;
					p->link=q->link;
					q->link=temp;
					if(p!=head)
						r->link=q;
					else
						head=q;
				        s->link=p;
				}
				else
				{
					p->link=q->link;
					q->link=p;
					if(p!=head)
						r->link=q;
					else
						head=q;
				}

				temp=p;
				p=q;
				q=temp;
			}
		}
	}
}

