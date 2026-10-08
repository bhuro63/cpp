#include<iostream.h>
#include<conio.h>

void main()
{
    int ch,n,i,j,s,k;

    clrscr();

    cout<<"1. Left Star"<<endl;
    cout<<"2. Reverse Star"<<endl;
    cout<<"3. Number"<<endl;
    cout<<"4. Reverse Number"<<endl;
    cout<<"5. Same Number"<<endl;
    cout<<"6. ABC"<<endl;
    cout<<"7. Reverse ABC"<<endl;
    cout<<"8. Square Star"<<endl;
    cout<<"9. Square Number"<<endl;
    cout<<"10. Right Star"<<endl;
    cout<<"11. Full Pyramid"<<endl;
    cout<<"12. Inverted Pyramid"<<endl;
    cout<<"13. Diamond"<<endl;
    cout<<"14. Floyd Triangle"<<endl;
    cout<<"15. 0-1 Pattern"<<endl;
    cout<<"16. Hollow Square"<<endl;
    cout<<"17. Hollow Pyramid"<<endl;
    cout<<"18. Butterfly"<<endl;
    cout<<"19. X Pattern"<<endl;
    cout<<"20. Sandglass"<<endl;

    cout<<"Enter Choice : ";
    cin>>ch;

    cout<<"Enter Rows : ";
    cin>>n;

    switch(ch)
    {
	case 1:
	    for(i=1;i<=n;i++)
	    {
		for(j=1;j<=i;j++)
		    cout<<" * ";
		cout<<endl;
	    }
	    break;

	case 2:
	    for(i=n;i>=1;i--)
	    {
		for(j=1;j<=i;j++)
		    cout<<" * ";
		cout<<endl;
	    }
	    break;

	case 3:
	    for(i=1;i<=n;i++)
	    {
		for(j=1;j<=i;j++)
		    cout<<"\t"<<j;
		cout<<endl;
	    }
	    break;

	case 4:
	    for(i=n;i>=1;i--)
	    {
		for(j=1;j<=i;j++)
		    cout<<j;
		cout<<endl;
	    }
	    break;

	case 5:
	    for(i=1;i<=n;i++)
	    {
		for(j=1;j<=i;j++)
		    cout<<i;
		cout<<endl;
	    }
	    break;

	case 6:
	    for(i=1;i<=n;i++)
	    {
		for(j=1;j<=i;j++)
		    cout<<(char)(64+j);
		cout<<endl;
	    }
	    break;

	case 7:
	    for(i=n;i>=1;i--)
	    {
		for(j=1;j<=i;j++)
		    cout<<(char)(64+j);
		cout<<endl;
	    }
	    break;

	case 8:
	    for(i=1;i<=n;i++)
	    {
		for(j=1;j<=n;j++)
		    cout<<"*";
		cout<<endl;
	    }
	    break;

	case 9:
	    for(i=1;i<=n;i++)
	    {
		for(j=1;j<=n;j++)
		    cout<<j;
		cout<<endl;
	    }
	    break;

	case 10:
	    for(i=1;i<=n;i++)
	    {
		for(s=1;s<=n-i;s++)
		    cout<<" ";

		for(j=1;j<=i;j++)
		    cout<<"*";

		cout<<endl;
	    }
	    break;

		case 11:
	    for(i=1;i<=n;i++)
	    {
		for(s=1;s<=n-i;s++)
		    cout<<" ";

		for(j=1;j<=i;j++)
		    cout<<"* ";

		cout<<endl;
	    }
	    break;





        case 12:
            for(i=n;i>=1;i--)
            {
                for(s=1;s<=n-i;s++)
                    cout<<" ";

                for(j=1;j<=i;j++)
                    cout<<"* ";

                cout<<endl;
            }
            break;


        case 13:
            for(i=1;i<=n;i++)
            {
                for(s=1;s<=n-i;s++)
                    cout<<" ";

                for(j=1;j<=i;j++)
                    cout<<"* ";

                cout<<endl;
            }

            for(i=n-1;i>=1;i--)
            {
                for(s=1;s<=n-i;s++)
                    cout<<" ";

                for(j=1;j<=i;j++)
                    cout<<"* ";

                cout<<endl;
            }
            break;


        case 14:
            k=1;
            for(i=1;i<=n;i++)
            {
                for(j=1;j<=i;j++)
                {
                    cout<<k<<" ";
                    k++;
                }
                cout<<endl;
            }
            break;


        case 15:
            for(i=1;i<=n;i++)
            {
                for(j=1;j<=i;j++)
                {
                    if((i+j)%2==0)
                        cout<<"1 ";
                    else
                        cout<<"0 ";
                }
                cout<<endl;
            }
            break;


        case 16:
            for(i=1;i<=n;i++)
            {
                for(j=1;j<=n;j++)
                {
                    if(i==1 || i==n || j==1 || j==n)
                        cout<<"*";
                    else
                        cout<<" ";
                }
                cout<<endl;
            }
            break;


        case 17:
            for(i=1;i<=n;i++)
            {
                for(s=1;s<=n-i;s++)
                    cout<<" ";

                for(j=1;j<=2*i-1;j++)
                {
                    if(i==n || j==1 || j==2*i-1)
                        cout<<"*";
                    else
                        cout<<" ";
                }
                cout<<endl;
            }
            break;


        case 18:
            for(i=1;i<=n;i++)
            {
                for(j=1;j<=i;j++)
                    cout<<"*";

                for(s=1;s<=2*(n-i);s++)
                    cout<<" ";

                for(j=1;j<=i;j++)
                    cout<<"*";

                cout<<endl;
            }

            for(i=n;i>=1;i--)
            {
                for(j=1;j<=i;j++)
                    cout<<"*";

                for(s=1;s<=2*(n-i);s++)
                    cout<<" ";

                for(j=1;j<=i;j++)
                    cout<<"*";

                cout<<endl;
            }
            break;


        case 19:
            for(i=1;i<=n;i++)
            {
                for(j=1;j<=n;j++)
                {
		    if(i==j || i+j==n+1)
			cout<<"*";
		    else
			cout<<" ";
		}
		cout<<endl;
	    }
	    break;


	case 20:
	    for(i=n;i>=1;i--)
	    {
		for(s=1;s<=n-i;s++)
		    cout<<" ";

		for(j=1;j<=2*i-1;j++)
		    cout<<"*";

		cout<<endl;
	    }

	    for(i=2;i<=n;i++)
	    {
		for(s=1;s<=n-i;s++)
		    cout<<" ";

		for(j=1;j<=2*i-1;j++)
		    cout<<"*";

		cout<<endl;
	    }
	    break;

	default:
	    cout<<"Wrong Choice";
    }

    getch();
}