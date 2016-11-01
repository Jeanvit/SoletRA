#include <SudaRA.h>
#include <sstream>
#include <math.h>
#include <stdlib.h>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <windows.h>
#include <time.h>
using namespace sudara;

//Variáveis globais
DWORD WINAPI ThreadProc(void *lpv);
bool executarfala,errou,acertou;
int valorMarcador[23],tempo,qtdacertos,qtderros,valTempoReal;
Audio *somAlfabeto[23],*parabens,*erro,*soletre,*repetindo,*somParabens,*somErro;
Audio *b[5],*c[5],*d[5],*fe[5],*g[5],*j[5],*l[5],*m[5],*n[5],*p[5],*r[5],*s[5],*t[5],*v[5],*x[5],*z[5];
GuiButton *repetir,*trocar, *fechar, *confirmar, *imagemAcerto, *imagemErro;
void declaraAudio() {
	somParabens =  new Audio;
	somParabens->load("../media/beep.wav");
	somErro =  new Audio;
	somErro->load("../media/marcardorsome.wav");
	parabens=new Audio;
	parabens->load("../media/parabens.wav");
	erro=new Audio;
	erro->load("../media/erro.wav");
	repetindo=new Audio;
	repetindo->load("../media/repetindo.wav");
	soletre=new Audio;
	soletre->load("../media/sequencia.wav");
	int i;
	for (i=0;i<=4;i++)
		b[i]= new Audio;
	b[0]->load("../media/ba.wav");
	b[1]->load("../media/be.wav");
	b[2]->load("../media/bi.wav");
	b[3]->load("../media/bo.wav");
	b[4]->load("../media/bu.wav");
	
	for (i=0;i<=4;i++)
		c[i]= new Audio;
	
	c[0]->load("../media/ca.wav");
	c[1]->load("../media/ce.wav");
	c[2]->load("../media/ci.wav");
	c[3]->load("../media/co.wav");
	c[4]->load("../media/cu.wav");
	for (i=0;i<=4;i++)
		d[i]= new Audio;

	d[0]->load("../media/da.wav");
	d[1]->load("../media/de.wav");
	d[2]->load("../media/di.wav");
	d[3]->load("../media/do.wav");
	d[4]->load("../media/du.wav");
	
	for (i=0;i<=4;i++)
		fe[i]= new Audio;
	
	fe[0]->load("../media/fa.wav");
	fe[1]->load("../media/fe.wav");
	fe[2]->load("../media/fi.wav");
	fe[3]->load("../media/fo.wav");
	fe[4]->load("../media/fu.wav");
	
	for (i=0;i<=4;i++)
		g[i]= new Audio;

	g[0]->load("../media/ga.wav");
	g[1]->load("../media/ge.wav");
	g[2]->load("../media/gi.wav");
	g[3]->load("../media/go.wav");
	g[4]->load("../media/gu.wav");
	
	for (i=0;i<=4;i++)
		l[i]= new Audio;
	
	l[0]->load("../media/la.wav");
	l[1]->load("../media/le.wav");
	l[2]->load("../media/li.wav");
	l[3]->load("../media/lo.wav");
	l[4]->load("../media/lu.wav");
	
	for (i=0;i<=4;i++)
		j[i]= new Audio;
	
	j[0]->load("../media/ja.wav");
	j[1]->load("../media/je.wav");
	j[2]->load("../media/ji.wav");
	j[3]->load("../media/jo.wav");
	j[4]->load("../media/ju.wav");
	
	for (i=0;i<=4;i++)
		m[i]= new Audio;

	m[0]->load("../media/ma.wav");
	m[1]->load("../media/me.wav");
	m[2]->load("../media/mi.wav");
	m[3]->load("../media/mo.wav");
	m[4]->load("../media/mu.wav");
	
	for (i=0;i<=4;i++)
		n[i]= new Audio;

	n[0]->load("../media/na.wav");
	n[1]->load("../media/ne.wav");
	n[2]->load("../media/ni.wav");
	n[3]->load("../media/no.wav");
	n[4]->load("../media/nu.wav");
	
	for (i=0;i<=4;i++)
		p[i]= new Audio;

	p[0]->load("../media/pa.wav");
	p[1]->load("../media/pe.wav");
	p[2]->load("../media/pi.wav");
	p[3]->load("../media/po.wav");
	p[4]->load("../media/pu.wav");
	
	for (i=0;i<=4;i++)
		r[i]= new Audio;

	r[0]->load("../media/ra.wav");
	r[1]->load("../media/re.wav");
	r[2]->load("../media/ri.wav");
	r[3]->load("../media/ro.wav");
	r[4]->load("../media/ru.wav");
	
	for (i=0;i<=4;i++)
		s[i]= new Audio;

	s[0]->load("../media/sa.wav");
	s[1]->load("../media/se.wav");
	s[2]->load("../media/si.wav");
	s[3]->load("../media/so.wav");
	s[4]->load("../media/su.wav");
	
	for (i=0;i<=4;i++)
		t[i]= new Audio;

	t[0]->load("../media/ta.wav");
	t[1]->load("../media/te.wav");
	t[2]->load("../media/ti.wav");
	t[3]->load("../media/to.wav");
	t[4]->load("../media/tu.wav");
	
	for (i=0;i<=4;i++)
		v[i]= new Audio;

	v[0]->load("../media/va.wav");
	v[1]->load("../media/ve.wav");
	v[2]->load("../media/vi.wav");
	v[3]->load("../media/vo.wav");
	v[4]->load("../media/vu.wav");
	
	for (i=0;i<=4;i++)
		x[i]= new Audio;

	x[0]->load("../media/xa.wav");
	x[1]->load("../media/xe.wav");
	x[2]->load("../media/xi.wav");
	x[3]->load("../media/xo.wav");
	x[4]->load("../media/xu.wav");

	for (i=0;i<=4;i++)
		z[i]= new Audio;

	z[0]->load("../media/za.wav");
	z[1]->load("../media/ze.wav");
	z[2]->load("../media/zi.wav");
	z[3]->load("../media/zo.wav");
	z[4]->load("../media/zu.wav");
}

typedef struct Falar{
	int numeroLetra[4];
	bool carregouAudio;
}Falar;

Falar *f = new Falar;
Falar *falaJogo = new Falar;

HANDLE hThreads;
DWORD dwThreadID;

void executaTempoReal(int valor){
	valTempoReal=valor;
}

//----------------------------------------------------------------------------------------------------------
int sorteiaConsoante(){
			int numero=rand()%24;
			if (numero==0 || numero==4 || numero==8 || numero==13|| numero==19)
				while (numero==0 || numero==4 || numero==8 || numero==13 || numero==19)
					numero=rand()%24;
			return numero;
		}
//----------------------------------------------------------------------------------------------------------
int sorteiaVogal(){
			int numero=rand()%24;
			if (numero!=0 && numero!=4 && numero!=8 && numero!=13|| numero!=19)
				while (numero!=0 && numero!=4 && numero!=8 && numero!=13 && numero!=19)
					numero=rand()%24;
			return numero;
		}
//----------------------------------------------------------------------------------------------------------
std::string Convert (float number){
			std::ostringstream buff;
			buff<<number;
			return buff.str();
}
//----------------------------------------------------------------------------------------------------------
void selecionaFala(int vogal, int consoante,int tipo){
	if (tipo==1) {
		while (vogal==falaJogo->numeroLetra[3] || vogal>23 || vogal <0)
			vogal=sorteiaVogal();
		while (consoante==falaJogo->numeroLetra[2] || vogal>23 || vogal <0)
			consoante=sorteiaConsoante();
	}
	switch (consoante) {
	case 1:
		somAlfabeto[1]->play();
		Sleep(1000);
		switch (vogal) {
			case 0:
				somAlfabeto[0]->play();
				Sleep(1000);
				b[0]->play();
				Sleep(1000);
				if (tipo==1) {
					falaJogo->numeroLetra[2]=1;
					falaJogo->numeroLetra[3]=0;
				}
				break;
			case 4 :
				somAlfabeto[4]->play();
				Sleep(1000);
				b[1]->play();
				Sleep(1000);
				if (tipo==1) {
					falaJogo->numeroLetra[2]=1;
					falaJogo->numeroLetra[3]=4;
				}
				break;
			case 8:
				somAlfabeto[8]->play();
				Sleep(1000);
				b[2]->play();
				Sleep(1000);
				if (tipo==1) {
					falaJogo->numeroLetra[2]=1;
					falaJogo->numeroLetra[3]=8;
				}
				break;
			case 13:
				somAlfabeto[13]->play();
				Sleep(1000);
				b[3]->play();
				Sleep(1000);
				if (tipo==1) {
					falaJogo->numeroLetra[2]=1;
					falaJogo->numeroLetra[3]=13;
				}
				break;
			case 19:
				somAlfabeto[19]->play();
				Sleep(1000);
				b[4]->play();
				Sleep(1000);
				if (tipo==1) {
					falaJogo->numeroLetra[2]=1;
					falaJogo->numeroLetra[3]=19;
				}
				break;
		}
		break;
	case 2:
		somAlfabeto[2]->play();
		Sleep(1000);
		switch (vogal) {
			case 0:
				somAlfabeto[0]->play();
				Sleep(1000);
				c[0]->play();
				Sleep(1000);
				if (tipo==1) {
					falaJogo->numeroLetra[2]=2;
					falaJogo->numeroLetra[3]=0;
				}
				break;
			case 4 :
				somAlfabeto[4]->play();
				Sleep(1000);
				c[1]->play();
				Sleep(1000);
				if (tipo==1) {
					falaJogo->numeroLetra[2]=2;
					falaJogo->numeroLetra[3]=4;
				}
				break;
			case 8:
				somAlfabeto[8]->play();
				Sleep(1000);
				c[2]->play();
				Sleep(1000);
				if (tipo==1) {
					falaJogo->numeroLetra[2]=2;
					falaJogo->numeroLetra[3]=8;
				}
				break;
			case 13:
				somAlfabeto[13]->play();
				Sleep(1000);
				c[3]->play();
				Sleep(1000);
				if (tipo==1) {
					falaJogo->numeroLetra[2]=2;
					falaJogo->numeroLetra[3]=13;
				}
				break;
			case 19:
				somAlfabeto[19]->play();
				Sleep(1000);
				c[4]->play();
				Sleep(1000);
				if (tipo==1) {
					falaJogo->numeroLetra[2]=2;
					falaJogo->numeroLetra[3]=19;
				}
				break;
		}
		break;
	case 3:
		somAlfabeto[3]->play();
		Sleep(1000);
		switch (vogal) {
			case 0:
				somAlfabeto[0]->play();
				Sleep(1000);
				d[0]->play();
				Sleep(1000);
				if (tipo==1) {
					falaJogo->numeroLetra[2]=3;
					falaJogo->numeroLetra[3]=0;
				}
				break;
			case 4 :
				somAlfabeto[4]->play();
				Sleep(1000);
				d[1]->play();
				Sleep(1000);
				if (tipo==1) {
					falaJogo->numeroLetra[2]=3;
					falaJogo->numeroLetra[3]=4;
				}
				break;
			case 8:
				somAlfabeto[8]->play();
				Sleep(1000);
				d[2]->play();
				Sleep(1000);
				if (tipo==1) {
					falaJogo->numeroLetra[2]=3;
					falaJogo->numeroLetra[3]=8;
				}
				break;
			case 13:
				somAlfabeto[13]->play();
				Sleep(1000);
				d[3]->play();
				Sleep(1000);
				if (tipo==1) {
					falaJogo->numeroLetra[2]=3;
					falaJogo->numeroLetra[3]=13;
				}
				break;
			case 19:
				somAlfabeto[19]->play();
				Sleep(1000);
				d[4]->play();
				Sleep(1000);
				if (tipo==1) {
					falaJogo->numeroLetra[2]=3;
					falaJogo->numeroLetra[3]=19;
				}
				break;
		}
		break;
	case 5:
		somAlfabeto[5]->play();
		Sleep(1000);
		switch (vogal) {
			case 0:
				somAlfabeto[0]->play();
				Sleep(1000);
				fe[0]->play();
				if (tipo==1) {
					falaJogo->numeroLetra[2]=5;
					falaJogo->numeroLetra[3]=0;
				}
				Sleep(1000);
				break;
			case 4 :
				somAlfabeto[4]->play();
				Sleep(1000);
				fe[1]->play();
				Sleep(1000);
				if (tipo==1) {
					falaJogo->numeroLetra[2]=5;
					falaJogo->numeroLetra[3]=4;
				}
				break;
			case 8:
				somAlfabeto[8]->play();
				Sleep(1000);
				fe[2]->play();
				Sleep(1000);
				if (tipo==1) {
					falaJogo->numeroLetra[2]=5;
					falaJogo->numeroLetra[3]=8;
				}
				break;
			case 13:
				somAlfabeto[13]->play();
				Sleep(1000);
				fe[3]->play();
				Sleep(1000);
				if (tipo==1) {
					falaJogo->numeroLetra[2]=5;
					falaJogo->numeroLetra[3]=13;
				}
				break;
			case 19:
				somAlfabeto[19]->play();
				Sleep(1000);
				fe[4]->play();
				Sleep(1000);
				if (tipo==1) {
					falaJogo->numeroLetra[2]=5;
					falaJogo->numeroLetra[3]=19;
				}
				break;
		}
		break;
	case 6:
		somAlfabeto[6]->play();
		Sleep(1000);
		switch (vogal) {
			case 0:
				somAlfabeto[0]->play();
				Sleep(1000);
				g[0]->play();
				Sleep(1000);
				if (tipo==1) {
					falaJogo->numeroLetra[2]=6;
					falaJogo->numeroLetra[3]=0;
				}
				break;
			case 4 :
				somAlfabeto[4]->play();
				Sleep(1000);
				g[1]->play();
				Sleep(1000);
				if (tipo==1) {
					falaJogo->numeroLetra[2]=6;
					falaJogo->numeroLetra[3]=4;
				}
				break;
			case 8:
				somAlfabeto[8]->play();
				Sleep(1000);
				g[2]->play();
				if (tipo==1) {
					falaJogo->numeroLetra[2]=6;
					falaJogo->numeroLetra[3]=8;
				}
				Sleep(1000);
				break;
			case 13:
				somAlfabeto[13]->play();
				Sleep(1000);
				g[3]->play();
				Sleep(1000);
				if (tipo==1) {
					falaJogo->numeroLetra[2]=6;
					falaJogo->numeroLetra[3]=13;
				}
				break;
			case 19:
				somAlfabeto[19]->play();
				Sleep(1000);
				g[4]->play();
				Sleep(1000);
				if (tipo==1) {
					falaJogo->numeroLetra[2]=6;
					falaJogo->numeroLetra[3]=19;
				}
				break;
		}
		break;
	case 7:
		somAlfabeto[7]->play();
		Sleep(1000);
		switch (vogal) {
			case 0:
				somAlfabeto[0]->play();
				Sleep(1000);
				somAlfabeto[0]->play();
				if (tipo==1) {
					falaJogo->numeroLetra[2]=7;
					falaJogo->numeroLetra[3]=0;
				}
				break;
			case 4 :
				somAlfabeto[4]->play();
				Sleep(1000);
				somAlfabeto[4]->play();
				if (tipo==1) {
					falaJogo->numeroLetra[2]=7;
					falaJogo->numeroLetra[3]=4;
				}
				break;
			case 8:
				somAlfabeto[8]->play();
				Sleep(1000);
				somAlfabeto[8]->play();
				if (tipo==1) {
					falaJogo->numeroLetra[2]=7;
					falaJogo->numeroLetra[3]=8;
				}
				break;
			case 13:
				somAlfabeto[13]->play();
				Sleep(1000);
				somAlfabeto[13]->play();
				if (tipo==1) {
					falaJogo->numeroLetra[2]=7;
					falaJogo->numeroLetra[3]=13;
				}
				break;
			case 19:
				somAlfabeto[19]->play();
				Sleep(1000);
				somAlfabeto[19]->play();
				if (tipo==1) {
					falaJogo->numeroLetra[2]=7;
					falaJogo->numeroLetra[3]=19;
				}
				break;
		}
		break;
	case 9:
		somAlfabeto[9]->play();
		Sleep(1000);
		switch (vogal) {
			case 0:
				somAlfabeto[0]->play();
				Sleep(1000);
				j[0]->play();
				Sleep(1000);
				if (tipo==1) {
					falaJogo->numeroLetra[2]=9;
					falaJogo->numeroLetra[3]=0;
				}
				break;
			case 4 :
				somAlfabeto[4]->play();
				Sleep(1000);
				j[1]->play();
				Sleep(1000);
				if (tipo==1) {
					falaJogo->numeroLetra[2]=9;
					falaJogo->numeroLetra[3]=4;
				}
				break;
			case 8:
				somAlfabeto[8]->play();
				Sleep(1000);
				j[2]->play();
				Sleep(1000);
				if (tipo==1) {
					falaJogo->numeroLetra[2]=9;
					falaJogo->numeroLetra[3]=8;
				}
				break;
			case 13:
				somAlfabeto[13]->play();
				Sleep(1000);
				j[3]->play();
				Sleep(1000);
				if (tipo==1) {
					falaJogo->numeroLetra[2]=9;
					falaJogo->numeroLetra[3]=13;
				}
				break;
			case 19:
				somAlfabeto[19]->play();
				Sleep(1000);
				j[4]->play();
				Sleep(1000);
				if (tipo==1) {
					falaJogo->numeroLetra[2]=9;
					falaJogo->numeroLetra[3]=19;
				}
				break;
		}
		break;
	case 10:
		somAlfabeto[10]->play();
		Sleep(1000);
		switch (vogal) {
			case 0:
				somAlfabeto[0]->play();
				Sleep(1000);
				l[0]->play();
				Sleep(1000);
				if (tipo==1) {
					falaJogo->numeroLetra[2]=10;
					falaJogo->numeroLetra[3]=0;
				}
				break;
			case 4 :
				somAlfabeto[4]->play();
				Sleep(1000);
				l[1]->play();
				Sleep(1000);
				if (tipo==1) {
					falaJogo->numeroLetra[2]=10;
					falaJogo->numeroLetra[3]=4;
				}
				break;
			case 8:
				somAlfabeto[8]->play();
				Sleep(1000);
				l[2]->play();
				Sleep(1000);
				if (tipo==1) {
					falaJogo->numeroLetra[2]=10;
					falaJogo->numeroLetra[3]=8;
				}
				break;
			case 13:
				somAlfabeto[13]->play();
				Sleep(1000);
				l[3]->play();
				Sleep(1000);
				if (tipo==1) {
					falaJogo->numeroLetra[2]=10;
					falaJogo->numeroLetra[3]=13;
				}
				break;
			case 19:
				somAlfabeto[19]->play();
				Sleep(1000);
				l[4]->play();
				Sleep(1000);
				if (tipo==1) {
					falaJogo->numeroLetra[2]=10;
					falaJogo->numeroLetra[3]=19;
				}
				break;
		}
		break;
	case 11:
		somAlfabeto[11]->play();
		Sleep(1000);
		switch (vogal) {
			case 0:
				somAlfabeto[0]->play();
				Sleep(1000);
				m[0]->play();
				Sleep(1000);
				if (tipo==1) {
					falaJogo->numeroLetra[2]=11;
					falaJogo->numeroLetra[3]=0;
				}
				break;
			case 4 :
				somAlfabeto[4]->play();
				Sleep(1000);
				m[1]->play();
				Sleep(1000);
				if (tipo==1) {
					falaJogo->numeroLetra[2]=11;
					falaJogo->numeroLetra[3]=4;
				}
				break;
			case 8:
				somAlfabeto[8]->play();
				Sleep(1000);
				m[2]->play();
				Sleep(1000);
				if (tipo==1) {
					falaJogo->numeroLetra[2]=11;
					falaJogo->numeroLetra[3]=8;
				}
				break;
			case 13:
				somAlfabeto[13]->play();
				Sleep(1000);
				m[3]->play();
				Sleep(1000);
				if (tipo==1) {
					falaJogo->numeroLetra[2]=11;
					falaJogo->numeroLetra[3]=13;
				}
				break;
			case 19:
				somAlfabeto[19]->play();
				Sleep(1000);
				m[4]->play();
				Sleep(1000);
				if (tipo==1) {
					falaJogo->numeroLetra[2]=11;
					falaJogo->numeroLetra[3]=19;
				}
				break;
		}
		break;
	case 12:
		somAlfabeto[12]->play();
		Sleep(1000);
		switch (vogal) {
			case 0:
				somAlfabeto[0]->play();
				Sleep(1000);
				n[0]->play();
				Sleep(1000);
				if (tipo==1) {
					falaJogo->numeroLetra[2]=12;
					falaJogo->numeroLetra[3]=0;
				}
				break;
			case 4 :
				somAlfabeto[4]->play();
				Sleep(1000);
				n[1]->play();
				Sleep(1000);
				if (tipo==1) {
					falaJogo->numeroLetra[2]=12;
					falaJogo->numeroLetra[3]=4;
				}
				break;
			case 8:
				somAlfabeto[8]->play();
				Sleep(1000);
				n[2]->play();
				Sleep(1000);
				if (tipo==1) {
					falaJogo->numeroLetra[2]=12;
					falaJogo->numeroLetra[3]=8;
				}
				break;
			case 13:
				somAlfabeto[13]->play();
				Sleep(1000);
				n[3]->play();
				Sleep(1000);
				if (tipo==1) {
					falaJogo->numeroLetra[2]=12;
					falaJogo->numeroLetra[3]=13;
				}
				break;
			case 19:
				somAlfabeto[19]->play();
				Sleep(1000);
				n[4]->play();
				Sleep(1000);
				if (tipo==1) {
					falaJogo->numeroLetra[2]=12;
					falaJogo->numeroLetra[3]=19;
				}
				break;
		}
		break;
	case 14:
		somAlfabeto[14]->play();
		Sleep(1000);
		switch (vogal) {
			case 0:
				somAlfabeto[0]->play();
				Sleep(1000);
				p[0]->play();
				Sleep(1000);
				if (tipo==1) {
					falaJogo->numeroLetra[2]=14;
					falaJogo->numeroLetra[3]=0;
				}
				break;
			case 4 :
				somAlfabeto[4]->play();
				Sleep(1000);
				p[1]->play();
				Sleep(1000);
				if (tipo==1) {
					falaJogo->numeroLetra[2]=14;
					falaJogo->numeroLetra[3]=4;
				}
				break;
			case 8:
				somAlfabeto[8]->play();
				Sleep(1000);
				p[2]->play();
				Sleep(1000);
				if (tipo==1) {
					falaJogo->numeroLetra[2]=14;
					falaJogo->numeroLetra[3]=8;
				}
				break;
			case 13:
				somAlfabeto[13]->play();
				Sleep(1000);
				p[3]->play();
				Sleep(1000);
				if (tipo==1) {
					falaJogo->numeroLetra[2]=14;
					falaJogo->numeroLetra[3]=13;
				}
				break;
			case 19:
				somAlfabeto[19]->play();
				Sleep(1000);
				p[4]->play();
				Sleep(1000);
				if (tipo==1) {
					falaJogo->numeroLetra[2]=14;
					falaJogo->numeroLetra[3]=19;
				}
				break;
		}
		break;
	case 16:
		somAlfabeto[16]->play();
		Sleep(1000);
		switch (vogal) {
			case 0:
				somAlfabeto[0]->play();
				Sleep(1000);
				r[0]->play();
				Sleep(1000);
				if (tipo==1) {
					falaJogo->numeroLetra[2]=16;
					falaJogo->numeroLetra[3]=0;
				}
				break;
			case 4 :
				somAlfabeto[4]->play();
				Sleep(1000);
				r[1]->play();
				Sleep(1000);
				if (tipo==1) {
					falaJogo->numeroLetra[2]=16;
					falaJogo->numeroLetra[3]=4;
				}
				break;
			case 8:
				somAlfabeto[8]->play();
				Sleep(1000);
				r[2]->play();
				Sleep(1000);
				if (tipo==1) {
					falaJogo->numeroLetra[2]=16;
					falaJogo->numeroLetra[3]=8;
				}
				break;
			case 13:
				somAlfabeto[13]->play();
				Sleep(1000);
				r[3]->play();
				Sleep(1000);
				if (tipo==1) {
					falaJogo->numeroLetra[2]=16;
					falaJogo->numeroLetra[3]=13;
				}
				break;
			case 19:
				somAlfabeto[19]->play();
				Sleep(1000);
				r[4]->play();
				Sleep(1000);
				if (tipo==1) {
					falaJogo->numeroLetra[2]=16;
					falaJogo->numeroLetra[3]=19;
				}
				break;
		}
		break;
	case 17:
		somAlfabeto[17]->play();
		Sleep(1000);
		switch (vogal) {
			case 0:
				somAlfabeto[0]->play();
				Sleep(1000);
				s[0]->play();
				Sleep(1000);
				if (tipo==1) {
					falaJogo->numeroLetra[2]=17;
					falaJogo->numeroLetra[3]=0;
				}
				break;
			case 4 :
				somAlfabeto[4]->play();
				Sleep(1000);
				s[1]->play();
				Sleep(1000);
				if (tipo==1) {
					falaJogo->numeroLetra[2]=17;
					falaJogo->numeroLetra[3]=4;
				}
				break;
			case 8:
				somAlfabeto[8]->play();
				Sleep(1000);
				s[2]->play();
				Sleep(1000);
				if (tipo==1) {
					falaJogo->numeroLetra[2]=17;
					falaJogo->numeroLetra[3]=8;
				}
				break;
			case 13:
				somAlfabeto[13]->play();
				Sleep(1000);
				s[3]->play();
				Sleep(1000);
				if (tipo==1) {
					falaJogo->numeroLetra[2]=17;
					falaJogo->numeroLetra[3]=13;
				}
				break;
			case 19:
				somAlfabeto[19]->play();
				Sleep(1000);
				s[4]->play();
				Sleep(1000);
				if (tipo==1) {
					falaJogo->numeroLetra[2]=17;
					falaJogo->numeroLetra[3]=19;
				}
				break;
		}
		break;
	case 18:
		somAlfabeto[18]->play();
		Sleep(1000);
		switch (vogal) {
			case 0:
				somAlfabeto[0]->play();
				Sleep(1000);
				t[0]->play();
				Sleep(1000);
				if (tipo==1) {
					falaJogo->numeroLetra[2]=18;
					falaJogo->numeroLetra[3]=0;
				}
				break;
			case 4 :
				somAlfabeto[4]->play();
				Sleep(1000);
				t[1]->play();
				Sleep(1000);
				if (tipo==1) {
					falaJogo->numeroLetra[2]=18;
					falaJogo->numeroLetra[3]=4;
				}
				break;
			case 8:
				somAlfabeto[8]->play();
				Sleep(1000);
				t[2]->play();
				Sleep(1000);
				if (tipo==1) {
					falaJogo->numeroLetra[2]=18;
					falaJogo->numeroLetra[3]=8;
				}
				break;
			case 13:
				somAlfabeto[13]->play();
				Sleep(1000);
				t[3]->play();
				Sleep(1000);
				if (tipo==1) {
					falaJogo->numeroLetra[2]=18;
					falaJogo->numeroLetra[3]=13;
				}
				break;
			case 19:
				somAlfabeto[19]->play();
				Sleep(1000);
				t[4]->play();
				Sleep(1000);
				if (tipo==1) {
					falaJogo->numeroLetra[2]=18;
					falaJogo->numeroLetra[3]=19;
				}
				break;
		}
		break;
	case 20:
		somAlfabeto[20]->play();
		Sleep(1000);
		switch (vogal) {
			case 0:
				somAlfabeto[0]->play();
				Sleep(1000);
				v[0]->play();
				Sleep(1000);
				if (tipo==1) {
					falaJogo->numeroLetra[2]=20;
					falaJogo->numeroLetra[3]=0;
				}
				break;
			case 4 :
				somAlfabeto[4]->play();
				Sleep(1000);
				v[1]->play();
				Sleep(1000);
				if (tipo==1) {
					falaJogo->numeroLetra[2]=20;
					falaJogo->numeroLetra[3]=4;
				}
				break;
			case 8:
				somAlfabeto[8]->play();
				Sleep(1000);
				v[2]->play();
				Sleep(1000);
				if (tipo==1) {
					falaJogo->numeroLetra[2]=20;
					falaJogo->numeroLetra[3]=8;
				}
				break;
			case 13:
				somAlfabeto[13]->play();
				Sleep(1000);
				v[3]->play();
				Sleep(1000);
				if (tipo==1) {
					falaJogo->numeroLetra[2]=20;
					falaJogo->numeroLetra[3]=13;
				}
				break;
			case 19:
				somAlfabeto[19]->play();
				Sleep(1000);
				v[4]->play();
				Sleep(1000);
				if (tipo==1) {
					falaJogo->numeroLetra[2]=20;
					falaJogo->numeroLetra[3]=19;
				}
				break;
		}
		break;
	case 21:
		somAlfabeto[21]->play();
		Sleep(1000);
		switch (vogal) {
			case 0:
				somAlfabeto[0]->play();
				Sleep(1000);
				x[0]->play();
				Sleep(1000);
				if (tipo==1) {
					falaJogo->numeroLetra[2]=21;
					falaJogo->numeroLetra[3]=0;
				}
				break;
			case 4 :
				somAlfabeto[4]->play();
				Sleep(1000);
				x[1]->play();
				Sleep(1000);
				if (tipo==1) {
					falaJogo->numeroLetra[2]=21;
					falaJogo->numeroLetra[3]=4;
				}
				break;
			case 8:
				somAlfabeto[8]->play();
				Sleep(1000);
				x[2]->play();
				Sleep(1000);
				if (tipo==1) {
					falaJogo->numeroLetra[2]=21;
					falaJogo->numeroLetra[3]=8;
				}
				break;
			case 13:
				somAlfabeto[13]->play();
				Sleep(1000);
				x[3]->play();
				Sleep(1000);
				if (tipo==1) {
					falaJogo->numeroLetra[2]=21;
					falaJogo->numeroLetra[3]=13;
				}
				break;
			case 19:
				somAlfabeto[19]->play();
				Sleep(1000);
				x[4]->play();
				Sleep(1000);
				if (tipo==1) {
					falaJogo->numeroLetra[2]=21;
					falaJogo->numeroLetra[3]=19;
				}
				break;
		}
		break;
	case 22:
		somAlfabeto[22]->play();
		Sleep(1000);
		switch (vogal) {
			case 0:
				somAlfabeto[0]->play();
				Sleep(1000);
				z[0]->play();
				Sleep(1000);
				if (tipo==1) {
					falaJogo->numeroLetra[2]=22;
					falaJogo->numeroLetra[3]=0;
				}
				break;
			case 4 :
				somAlfabeto[4]->play();
				Sleep(1000);
				z[1]->play();
				Sleep(1000);
				if (tipo==1) {
					falaJogo->numeroLetra[2]=22;
					falaJogo->numeroLetra[3]=4;
				}
				break;
			case 8:
				somAlfabeto[8]->play();
				Sleep(1000);
				z[2]->play();
				Sleep(1000);
				if (tipo==1) {
					falaJogo->numeroLetra[2]=22;
					falaJogo->numeroLetra[3]=8;
				}
				break;
			case 13:
				somAlfabeto[13]->play();
				Sleep(1000);
				z[3]->play();
				Sleep(1000);
				if (tipo==1) {
					falaJogo->numeroLetra[2]=22;
					falaJogo->numeroLetra[3]=13;
				}
				break;
			case 19:
				somAlfabeto[19]->play();
				Sleep(1000);
				z[4]->play();
				Sleep(1000);
				if (tipo==1) {
					falaJogo->numeroLetra[2]=22;
					falaJogo->numeroLetra[3]=19;
				}
				break;
		}
		break;
	}
}
//----------------------------------------------------------------------------------------------------------
bool verificaVogal () {
	int contador=0;
	while (contador<=3 || f->numeroLetra[contador]!=-1) {
		if (f->numeroLetra[contador]== 0|| f->numeroLetra[contador]==8 || f->numeroLetra[contador]==4 || f->numeroLetra[contador]==13 || f->numeroLetra[contador]==19){
			return true;
		}
		contador++;
	}
	return false;
}
//----------------------------------------------------------------------------------------------------------
bool verificaConsoante () {
	int contador=0;
	while (contador<=3 || f->numeroLetra[contador]!=-1) {
		if (f->numeroLetra[contador]!= 0 && f->numeroLetra[contador]!=8 && f->numeroLetra[contador]!=4 && f->numeroLetra[contador]!=13 && f->numeroLetra[contador]!=19){
			return true;
		}
		contador++;
	}
	return false;
}
//---------------------------------------------------------------------------------------------------------
void moveConsoante() {
	int temp;
	if (f->numeroLetra[0]==0 || f->numeroLetra[0]==4 || f->numeroLetra[0]==8 || f->numeroLetra[0]==13|| f->numeroLetra[0]==19)
		if (f->numeroLetra[1]!=0 && f->numeroLetra[1]!=4 && f->numeroLetra[1]!=8 && f->numeroLetra[1]!=13 && f->numeroLetra[1]!=19) {
			temp=f->numeroLetra[1];
			f->numeroLetra[1]=f->numeroLetra[0];
			f->numeroLetra[0]=temp;
		}
}
//----------------------------------------------------------------------------------------------------------
DWORD WINAPI ThreadProc3(void *lpv)
{
		selecionaFala(f->numeroLetra[1],f->numeroLetra[0],0);
		return 0;
}
//----------------------------------------------------------------------------------------------------------
DWORD WINAPI ThreadProc4(void *lpv)
{
		selecionaFala(falaJogo->numeroLetra[1],falaJogo->numeroLetra[0],0);
		return 0;
}
//----------------------------------------------------------------------------------------------------------
//CLASSE PRINCIPAL DA THREAD;
DWORD WINAPI ThreadProc(void *lpv)
{
	int i,posLetras=0;
	std::string con;
	if (f->carregouAudio==false) {
		for(i=65;i<=90;i++) {
					somAlfabeto[posLetras] = new Audio;
					if (i==75 || i==87 || i== 89)
						i++;
					con=(char)i;
					somAlfabeto[posLetras]->load("../media/"+con+ ".wav");
					posLetras++;
		}
		f->carregouAudio=true;
	}
	i=0;
	while (f->numeroLetra[i]!=-1) {
		i++;
	}
	if (verificaVogal() &&  verificaConsoante() && i>=1){
		moveConsoante();
		CreateThread(NULL,NULL,&ThreadProc3,falaJogo,NULL,&dwThreadID);
		if (f->numeroLetra[1]==falaJogo->numeroLetra[3] && f->numeroLetra[0]==falaJogo->numeroLetra[2]) {
			Sleep(3000);
			somParabens->play();
			parabens->play();
			std::cout<<"Acertou: " + Convert(falaJogo->numeroLetra[2]) + "  " + Convert(falaJogo->numeroLetra[3]) +"\n";
			acertou=true;
			qtdacertos++;
		}
		else{
			Sleep(3000);
			somErro->play();
			erro->play();
			errou=true;
			qtderros++;
		}
	}
	else { 
		somErro->play();
		erro->play();
		errou=true;
		qtderros++;
	}

	return 0;
}
//---------------------------------------------------------------------------------------------------------- 
DWORD WINAPI ThreadProc2(void *lpv)
{
		selecionaFala(falaJogo->numeroLetra[1],falaJogo->numeroLetra[0],1);
		return 0;
}
//---------------------------------------------------------------------------------------------------------- 
static class VrmlSample : public ARApplication
{
	private:
		GuiText *infoScene;
	public:
		VrmlSample() : ARApplication() {}
		Scene *marcador2 ;
		Scene *scene;
		Scene *marcador[23];
		std::string msg;
		int lsorteio,vsorteio;
		bool fala;
		int numeroMarcador;
		int contMarcador;
		clock_t tempoInicial, tempoFinal;
		StaticModel *alfabeto[23],*vogais[5];
		Audio *somVogais[5];
		int i,j;
		int posLetras;
		std::string con,vog;
		std::string texto;
//----------------------------------------------------------------------------------------------------------------
		void initialize()
		{
			qtderros=0;
			qtdacertos=0;
			tempo=0;
			errou=false;
			acertou=false;
			imagemErro = new GuiButton();
			imagemAcerto = new GuiButton();
			trocar = new GuiButton();
			repetir = new GuiButton();
			confirmar = new GuiButton();
			fechar = new GuiButton();
			trocar->load(Vector(350, 417), "../media/btTrocar.png");
			repetir->load(Vector(420, 417), "../media/btTocar.png");
			confirmar->load(Vector(490, 417), "../media/btConfirmar.png");
			fechar->load (Vector(570, 417), "../media/btSair.png");
			imagemErro->load (Vector(200, 120), "../media/errado.png");
			imagemAcerto->load (Vector(200, 120), "../media/correto.png");
			declaraAudio();
			f->carregouAudio=false;
			tempoInicial = clock();
			contMarcador=0;
			numeroMarcador=-1;
			fala=false;
			srand(time(NULL));	
			//Organizando a cena
			this->guiWindow = new GuiWindow;
			this->guiWindow->addEntity(repetir,	"Repetir");
			this->guiWindow->addEntity(confirmar,	"Confirmar");
			this->guiWindow->addEntity(fechar,	"Fechar");
			this->guiWindow->addEntity(trocar,	"Trocar");
				posLetras=0;
			for(i=65;i<=90;i++) {
				con="";
				alfabeto[posLetras] = new StaticModel;
				somAlfabeto[posLetras] = new Audio;
				if (i==75 || i==87 || i== 89)
					i++;
				con=(char)i;
				alfabeto[posLetras]->load("../media/"+ con + ".obj");
				alfabeto[posLetras]->setScale(150);
				somAlfabeto[posLetras]->load("../media/"+con+ ".wav");
				texto="../media/" + con + "patt";
				marcador[posLetras]= new Scene;
				marcador[posLetras]->load(texto.c_str());
				marcador[posLetras]->addEntity(alfabeto[posLetras]);
				addScene(marcador[posLetras],con);
				posLetras++;
			}
			this->infoScene = new GuiText;
			this->infoScene->load(Vector(10, 10), "", "../media/arial.ttf", Vector(1, 1, 1), 20);
			this->guiWindow->addEntity(this->infoScene);
			this->infoScene->setText(msg);
			sorteiaFala();
			system ("cls");
		}
//----------------------------------------------------------------------------------------------------------------
		void sorteiaFala() {
			falaJogo->numeroLetra[0]=sorteiaConsoante();
			falaJogo->numeroLetra[1]=sorteiaVogal();
			CreateThread(NULL,NULL,&ThreadProc2,f,NULL,&dwThreadID);	
		}
//----------------------------------------------------------------------------------------------------------------
		void update(int elapsedTime)
		{
			this->tempoFinal=clock()/CLOCKS_PER_SEC;
			msg="Tempo = ";
			msg = msg + Convert(tempoFinal);
			msg = msg + "          Acertos: " + Convert(qtdacertos);
			msg = msg + "      Erros:" + Convert(qtderros); 
			this->infoScene->setText(msg);
			numeroMarcador= contMarcador;
			contMarcador=0;
			for (i=0;i<23;i++) {
				if (marcador[i]->isVisible()) {
					valorMarcador[contMarcador]=i;
					contMarcador++;
				}
			}
			if (numeroMarcador!=contMarcador)
				for (j=0;j<contMarcador;j++){
					somAlfabeto[valorMarcador[j]]->play();
				}
		if (errou==true) {
			this->guiWindow->addEntity(imagemErro,"erro");
		}
		if (acertou==true) {
			this->guiWindow->addEntity(imagemAcerto,"certo");
		}
		if (tempo==0 && (acertou==true || errou==true)) {
			tempo=clock()/CLOCKS_PER_SEC;
		}
		if (tempoFinal-tempo>3 && errou==true) {
			tempo=0;
			errou=false;
			this->guiWindow->removeEntity("erro");
		}
		if (tempoFinal-tempo>3 && acertou==true) {
			tempo=0;
			acertou=false;
			this->guiWindow->removeEntity("certo");
		}
	}
//----------------------------------------------------------------------------------------------------------------
		void onGuiButtonPressed(std::string idButton)
		{
			int cont;
			if (idButton == "Trocar")
				sorteiaFala();
			if (idButton == "Fechar")
				exit();
			if (idButton == "Confirmar") {
				f->numeroLetra[0]=-1;
				f->numeroLetra[1]=-1;
				f->numeroLetra[2]=-1;
				for (cont=0;cont<contMarcador;cont++) 
					f->numeroLetra[cont]=valorMarcador[cont];
				CreateThread(NULL,NULL,&ThreadProc,f,NULL,&dwThreadID);	
			}
			if (idButton == "Repetir")
				CreateThread(NULL,NULL,&ThreadProc4,f,NULL,&dwThreadID);

}
//----------------------------------------------------------------------------------------------------------------
		void onKeyPressed(KeyboardButton key) 
		{
			int cont;
			switch (key) {
			case KEY_RETURN:
				f->numeroLetra[0]=-1;
				f->numeroLetra[1]=-1;
				f->numeroLetra[2]=-1;
				for (cont=0;cont<contMarcador;cont++) 
					f->numeroLetra[cont]=valorMarcador[cont];
				CreateThread(NULL,NULL,&ThreadProc,f,NULL,&dwThreadID);
			}
		}
//----------------------------------------------------------------------------------------------------------------
		bool espera(int tempo) {
			time_t inicial,andamento;
			inicial=tempoFinal;
			andamento=clock();
			while (andamento-inicial<=tempo){
				andamento=clock();
			}
			return true;
		}
//----------------------------------------------------------------------------------------------------------------
}; 
   
int main(int argc, char **argv)
{
		
		VrmlSample().go("SoletRA - Aprenda brincando!", "../media/WDM_camera_flipV.xml", "../media/camera_para.dat");
	    return (0);
}