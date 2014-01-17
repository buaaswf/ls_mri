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
	int l = 512,m = 512,n = 144, l1=0,l2=0,iter_outer=10;
	RawImage test;
	char dirbody[100];

	short * indata=test.readMRI("K:\\sdf\\MRI\\SE1512_512_144.raw",&l,&m,&n);
	Raw *initial=new Raw(l,m,n);
	float *inputo=new float[l*m*n];
	for (int i = 0; i < l*m*n; i++)
	{
		if ( inputo[i] >= 900 && inputo[i] <= 1200 )
		{
			inputo[i] = 100;
		} 
		else
		{
			inputo[i] = 0;
		}
		
		//inputo[i]=(float) indata[i];		
	}

	Raw *input=new Raw(l,m,n,inputo);

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
int main()
{
	testMRI3();
	getchar();
}