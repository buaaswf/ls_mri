#include "ThreeDim_Levelset.h"

void testMRI0()
{
	char *pt="single_well";
	int l = 512,m = 512,n = 4, l1=0,l2=0,iter_outer=10;
	RawImage test;
	char dirbody[100];

	short * indata=test.readMRI("K:\\sdf\\MRI\\SE1512_512_144.raw",&l,&m,&n);
	Raw *initial=new Raw(l,m,n);
	float *inputo=new float[l*m*n];
	for (int i = 0; i < l*m*n; i++)
	{
		inputo[i]=(float) indata[i];		
	}

	Raw *input=new Raw(l,m,n,inputo);
	//Filter *f=new Filter();
	//input=f->guass3DFilter(input,3);
	RawImage *write=new RawImage();
	ThreeDim_LevelSet *ls=new ThreeDim_LevelSet();
	ls->initialg(*input);
	for (int i=0; i<input->getXsize(); i++)
	{
		for (int j=0; j<input->getYsize(); j++)
		{
			for (int k=0; k<input->getZsize(); k++)
			{
				if (input->get(i,j,k)>=1)
				{
					initial->put(i,j,k,-2);
				}
				else initial->put(i,j,k,2);

			}
		}

	}
	//*initial=ls->minimal_surface(*initial,*input,5.0,0.1,-3,1.5,1,iter_outer,pt);
	test.writeMRI(*input,"K:\\sdf\\MRI\\SE1512_512_144out.raw");
	//Raw temp(*initial);
	//ls->outerwallauto(*initial,*input,5.0,0.1,-3,1.5,1,10,pt);
	////*initial -=temp;
	//char *outname2="autoouter5-8_2.raw";
	//char outdir2[200]=output;
	//strcat(outdir2,dirbody);
	//strcat(outdir2,outname2);
	//test.writeImageName(*initial,outdir2);
	//evaluate(dir,l,m,n);

}
void testMRI1()
{
	char *pt="single_well";
	int l = 512,m = 512,n = 144, l1=0,l2=0,iter_outer=10;
	RawImage test;
	char dirbody[100];

	short * indata=test.readMRI("K:\\sdf\\MRI\\SE1512_512_144.raw",&l,&m,&n);
	Raw *initial=new Raw(l,m,n);
	float *inputo=new float[l*m*n];
	for (int i = 0; i < l*m*n; i++)
	{
		inputo[i]=(float) indata[i];		
	}

	Raw *input=new Raw(l,m,n,inputo);
	//Filter *f=new Filter();
	//input=f->guass3DFilter(input,3);
	RawImage *write=new RawImage();
	ThreeDim_LevelSet *ls=new ThreeDim_LevelSet();
	ls->initialg(*input);
	int x1= 198 ,y1 = 208  , z1 = 40,
		x12 =295 ,y12 =212 ,z12  = 40,
		x13,y13,z13,
		x14,y14,z14,
		x2 = 232, y2 = 290, z2 =50 ,
		x22 =332 ,y22 = 293,z22=50,
		x23,y23,z23,
		x24,y24,z24;
	for (int i=0; i<input->getXsize(); i++)
	{
		for (int j=0; j<input->getYsize(); j++)
		{
			for (int k=0; k<input->getZsize(); k++)
			{
				if (input->get(i,j,k)>=1)
				{
					initial->put(i,j,k,-2);
				}
				else initial->put(i,j,k,2);
				//region 1
				if (i>x1 && j>y1 && k>z1 && i<x2 && j<y2 && k<z2)
				{
					initial->put(i,j,k,-2.0);
				} 
				else if (i<x1|| j<y1 || k < z1 || i>x2 || j>y2 || k> z2)
				{
					initial->put(i,j,k,2.0);
				}
				else {
					initial->put(i,j,k,-2.0);
				}
				//region 2
					if (i>x12 && j>y12 && k>z12 && i<x22 && j<y22 && k<z22)
					{
						initial->put(i,j,k,-2.0);
					} 
					else if (i<x12|| j<y12 || k < z12 || i>x22 || j>y22 || k> z22)
					{
						initial->put(i,j,k,2.0);
					}
					else {
						initial->put(i,j,k,-2.0);
					}
					//region 3
					//if (i>x13 && j>y13 && k>z13 && i<x23 && j<y23 && k<z23)
					//{
					//	initial->put(i,j,k,-2.0);
					//} 
					//else if (i<x14|| j<y14 || k < z14 || i>x24 || j>y24 || k> z24);


			}
		}

	}
	*initial=ls->minimal_surface(*initial,*input,5.0,0.1,-3,1.5,1,iter_outer,pt);
	test.writeMRI(*input,"K:\\sdf\\MRI\\SE1512_512_144out2regions.raw");
	//Raw temp(*initial);
	//ls->outerwallauto(*initial,*input,5.0,0.1,-3,1.5,1,10,pt);
	////*initial -=temp;
	//char *outname2="autoouter5-8_2.raw";
	//char outdir2[200]=output;
	//strcat(outdir2,dirbody);
	//strcat(outdir2,outname2);
	//test.writeImageName(*initial,outdir2);
	//evaluate(dir,l,m,n);

}
void testMRI2()
{
	char *pt="single_well";
	int l = 512,m = 512,n = 144, l1=0,l2=0,iter_outer=10;
	RawImage test;
	char dirbody[100];

	short * indata=test.readMRI("K:\\sdf\\MRI\\SE1512_512_144.raw",&l,&m,&n);
	Raw *initial=new Raw(l,m,n);
	float *inputo=new float[l*m*n];
	for (int i = 0; i < l*m*n; i++)
	{
		
		inputo[i]=(float) indata[i];		
	}

	Raw *input=new Raw(l,m,n,inputo);
	for (int i=0; i<input->getXsize(); i++)
	{
		for (int j=0; j<input->getYsize(); j++)
		{
			for (int k=0; k<input->getZsize(); k++)
			{
				if (input->get(i,j,k) >= 900 && input->get(i,j,k) <= 1200)
				{
					initial->put(i,j,k,-2.0);
				}
				else
				{
					initial->put(i,j,k,2.0);
				}

			}
		}

	}
	//Filter *f=new Filter();
	//input=f->guass3DFilter(input,3);
	RawImage *write=new RawImage();
	ThreeDim_LevelSet *ls=new ThreeDim_LevelSet();
	ls->initialg(*input);
	//int x1= 198 ,y1 = 208  , z1 = 40,
	//	x12 =295 ,y12 =212 ,z12  = 40,
	//	x13,y13,z13,
	//	x14,y14,z14,
	//	x2 = 232, y2 = 290, z2 =50 ,
	//	x22 =332 ,y22 = 293,z22=50,
	//	x23,y23,z23,
	//	x24,y24,z24;

	*initial=ls->minimal_surface(*initial,*input,5.0,0.1,-3,1.5,1,iter_outer,pt);
	test.writeMRI(*input,"K:\\sdf\\MRI\\SE1512_512_144out2regions.raw");
	//Raw temp(*initial);
	//ls->outerwallauto(*initial,*input,5.0,0.1,-3,1.5,1,10,pt);
	////*initial -=temp;
	//char *outname2="autoouter5-8_2.raw";
	//char outdir2[200]=output;
	//strcat(outdir2,dirbody);
	//strcat(outdir2,outname2);
	//test.writeImageName(*initial,outdir2);
	//evaluate(dir,l,m,n);
}
void testMRI3()
{
	char *pt="single_well";
	int l = 512,m = 512,n = 144, l1=0,l2=0,iter_outer= 10;
	RawImage test;
	char dirbody[100];

	short * indata=test.readMRI("K:\\sdf\\MRI\\SE1512_512_144.raw",&l,&m,&n);//F:\\PA1\\ST1\\SE1\\  //K:\\sdf\\MRI\\

	Raw *initial=new Raw(l,m,n);
	float *inputo=new float[l*m*n];
	short min =-1000,max =0;
	for (int i = 0; i < l*m*n; i++)
	{
		float * p= (float *)(indata+i);
		unsigned char * bp= (unsigned char *)p;
		std:swap(bp[0],bp[3]);
		std::swap(bp[1],bp[2]);
		min < indata[i] ? min=min:min=indata[i];
		max > indata[i] ? max=max:max=indata[i];
		
		if ( indata[i] >= 864 && indata[i] <= 1063 )
		{
			inputo[i] = (float)100;
		} 
		else
		{
			inputo[i] = (float )0;
		}
		
		//inputo[i]=(short) indata[i];		
	}

	cout <<min << max <<endl;

	Raw *input=new Raw(l,m,n,inputo);
	for (int i=0; i<input->getZsize(); i++)
	{
		for (int j=0; j<input->getYsize(); j++)
		{
			for (int k=0; k<input->getXsize(); k++)
			{
				//if (input->get(i,j,k) >= 1)
				//{
				//	initial->put(i,j,k,-2);
				//}
				//else initial->put(i,j,k, 2);
				//int 	pos= i*input->getYsize()*input->getXsize()+j*input->getXsize()+k;
				//if (i >= 196 && i <= 220 && j >= 202 && j <= 267 && k > 40 && k < 50 && input->get(i,j,k) >= 1)
				if (k >= 160 && k <= 400 && j >= 140 && j <= 400 && i > 10 && i < 140 && input->get(k,j,i) == 100)
					//if ( input->get(i,j,k) >= 1)
				{
					initial->put(k,j,i,-2);
				} 
				else
				{
					initial->put(k,j,i,2);
				}


			}
		}

	}
	//Filter *f=new Filter();
	//input=f->guass3DFilter(input,3);
	RawImage *write=new RawImage();
	ThreeDim_LevelSet *ls=new ThreeDim_LevelSet();
	ls->initialg(*input);
	
	


	*initial=ls->minimal_surface(*initial,*input,5.0,0.1,-3,1.5,1,iter_outer,pt);
	test.writeMRI(*initial,"K:\\sdf\\MRI\\SE1512_512_144.rawout2regions.raw");
	//Raw temp(*initial);
	//ls->outerwallauto(*initial,*input,5.0,0.1,-3,1.5,1,10,pt);
	////*initial -=temp;
	//char *outname2="autoouter5-8_2.raw";
	//char outdir2[200]=output;
	//strcat(outdir2,dirbody);
	//strcat(outdir2,outname2);
	//test.writeImageName(*initial,outdir2);
	//evaluate(dir,l,m,n);
}
void testMRI4elilpse()
{
	char *pt="single_well";
	int l = 512,m = 512,n = 144, l1=0,l2=0,iter_outer = 50;
	RawImage test;
	char dirbody[100];

	short * indata;///=test.readMRI("K:\\sdf\\MRI\\SE1512_512_144.raw",&l,&m,&n);//F:\\PA1\\ST1\\SE1\\  //K:\\sdf\\MRI\\
	
	indata =new short[l*m*n];
	for (int k =0; k < n; k++ )
	{
		for ( int j = 0; j < m; j++)
		{
			for ( int i = 0; i < l; i++)
			{
				//if ( i < 300 && i > 100 && j < 300 && j > 200 && k > 30 && k < 60 )
			
				if ( ((i-200) * (i-200) /(double)( 100 * 100 ) + (j -250)* (j - 250) /(double)( 50 * 50 ) +  (k-45) * (k-45) /(double)(15 * 15) < 1))
				{
					indata[i + j*l + k*m*l] = 100;
				} 
				else
				{
					indata[i + j*l + k*m*l] = 0;
				}
			}
		}
		
	}
	Raw *initial=new Raw(l,m,n);
	float *inputo=new float[l*m*n];
	short min = 1000,max = -100;
	for (int i = 0; i < l*m*n; i++)
	{
		float * p= (float *)(indata+i);
		//unsigned char * bp= (unsigned char *)p;
		//std:swap(bp[0],bp[3]);
		//std::swap(bp[1],bp[2]);
		min < indata[i] ? min=min:min=indata[i];
		max > indata[i] ? max=max:max=indata[i];
		
	/*	if ( indata[i] >= 864 && indata[i] <= 1063 )
		{
			inputo[i] = 100;
		} 
		else
		{
			inputo[i] = (short )0;
		}
		*/
		inputo[i]=(short) indata[i];		
	}

	cout <<min << max <<endl;

	Raw *input=new Raw(l,m,n,inputo);

	//Filter *f=new Filter();
	//input=f->guass3DFilter(input,3);
	RawImage *write=new RawImage();
	ThreeDim_LevelSet *ls=new ThreeDim_LevelSet();
	//ls->initialg(*input);
	//for (int i = 0 ; i < l; i++ )
	//{
	//	for ( int j = 0; j < m; j++)
	//	{
	//		for ( int k = 0; k < n; k++ )
	//		{
	//			if ( !(i > 172 && i < 352 && j > 164 && j < 376))
	//			{
	//				input->put(i,j,k,0); 
	//			}
	//		}
	//	}
	//}
	//int x1= 198 ,y1 = 208  , z1 = 40,
	//	x12 =295 ,y12 =212 ,z12  = 40,
	//	x13,y13,z13,
	//	x14,y14,z14,
	//	x2 = 232, y2 = 290, z2 =50 ,
	//	x22 =332 ,y22 = 293,z22=50,
	//	x23,y23,z23,
	//	x24,y24,z24;
	for (int i=0; i<input->getXsize(); i++)
	{
		for (int j=0; j<input->getYsize(); j++)
		{
			for (int k=0; k<input->getZsize(); k++)
			{
				//if (input->get(i,j,k) >= 1)
				//{
				//	initial->put(i,j,k,-2);
				//}
				//else 
					//if ((i >= 172 && i <= 352 && j >= 164 && j <= 376 && z>19 && z <))
				if ((i >= 196 && i <= 220 && j >= 202 && j <= 267 && k > 40 && k < 50))
				{
					initial->put(i, j, k, -2);
				} 
				else
				{
					initial->put(i, j, k, 2);
				}


			}
		}

	}
	//*initial=ls->minimal_surface(*initial,*input,5.0,0.1,-3,1.5,1,iter_outer,pt);//if you available this, don,t
	//forget to change the next line to initial
	test.writeMRI(*initial,"K:\\sdf\\MRI\\SE1512_512_144.testdata.raw");//F:\\PA1\\ST1\\SE1
	//Raw temp(*initial);
	//ls->outerwallauto(*initial,*input,5.0,0.1,-3,1.5,1,10,pt);
	////*initial -=temp;
	//char *outname2="autoouter5-8_2.raw";
	//char outdir2[200]=output;
	//strcat(outdir2,dirbody);
	//strcat(outdir2,outname2);
	//test.writeImageName(*initial,outdir2);
	//evaluate(dir,l,m,n);
}
void testMRI5retangle()
{
	char *pt="single_well";
	int l = 512,m = 512,n = 144, l1=0,l2=0,iter_outer = 50;
	RawImage test;
	char dirbody[100];

	short * indata;///=test.readMRI("K:\\sdf\\MRI\\SE1512_512_144.raw",&l,&m,&n);//F:\\PA1\\ST1\\SE1\\  //K:\\sdf\\MRI\\
	
	indata =new short[l*m*n];
	for (int k =0; k < n; k++ )
	{
		for ( int j = 0; j < m; j++)
		{
			for ( int i = 0; i < l; i++)
			{
				//if ( i < 300 && i > 100 && j < 300 && j > 200 && k > 30 && k < 60 )
			
				if ( (i >= 190 && i <= 230 && j >= 200 && j <= 270 && k > 35 && k < 55))
				{
					indata[i + j*l + k*m*l] = 1;
				} 
				else
				{
					indata[i + j*l + k*m*l] = 0;
				}
			}
		}
		
	}
	Raw *initial=new Raw(l,m,n);
	float *inputo=new float[l*m*n];
	short min = 1000,max = -100;
	for (int i = 0; i < l*m*n; i++)
	{
		float * p= (float *)(indata+i);
		//unsigned char * bp= (unsigned char *)p;
		//std:swap(bp[0],bp[3]);
		//std::swap(bp[1],bp[2]);
		min < indata[i] ? min=min:min=indata[i];
		max > indata[i] ? max=max:max=indata[i];
		
	/*	if ( indata[i] >= 864 && indata[i] <= 1063 )
		{
			inputo[i] = 100;
		} 
		else
		{
			inputo[i] = (short )0;
		}
		*/
		inputo[i]=(float) indata[i];		
	}

	cout <<min << max <<endl;

	Raw *input=new Raw(l,m,n,inputo);

	//Filter *f=new Filter();
	//input=f->guass3DFilter(input,3);
	RawImage *write=new RawImage();
	ThreeDim_LevelSet *ls=new ThreeDim_LevelSet();
	//ls->initialg(*input);
	for (int i=0; i<input->getXsize(); i++)
	{
		for (int j=0; j<input->getYsize(); j++)
		{
			for (int k=0; k<input->getZsize(); k++)
			{
				//if (input->get(i,j,k) >= 1)
				//{
				//	initial->put(i,j,k,-2);
				//}
				//else 
					//if ((i >= 172 && i <= 352 && j >= 164 && j <= 376 && z>19 && z <))
				if ((i >= 196 && i <= 220 && j >= 202 && j <= 267 && k > 40 && k < 50))
				{
					initial->put(i, j, k, -2);
				} 
				else
				{
					initial->put(i, j, k, 2);
				}


			}
		}

	}
	*initial=ls->minimal_surface(*initial,*input,5.0,0.1,-3,1.5,1,iter_outer,pt);
	//if you available this, don,t
	//forget to change the next line to initial
	test.writeMRI(*initial,"K:\\sdf\\MRI\\SE1512_512_144.testdata.raw");//F:\\PA1\\ST1\\SE1
	
}
int main()
{
	testMRI3();
	getchar();
}