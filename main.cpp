#include <iostream>
#include <vector>
#include <string>
#include <ctime>
#include <cstdlib>
#include <windows.h>
#include <iomanip>
#include <fstream>

using namespace std;


//VETTORE  CON VALORE DI OGNI LETTERA
vector <int> valorelettere={1,4,1,4,1,4,4,8,1,0,0,2,2,2,1,3,10,1,1,1,4,4,0,0,0,8};

//VETTORE "SACCHETTO"
vector <char> alfabeto={'a','a','a','a','a','a','a','a','a','a','a','a',
                        'b','b','b','b',
                        'c','c','c','c','c','c','c',
                        'd','d','d','d',
                        'e','e','e','e','e','e','e','e','e','e','e','e',
                        'f','f','f','f',
                        'g','g','g','g',
                        'h','h',
                        'i','i','i','i','i','i','i','i','i','i','i','i',
                        'l','l','l','l','l','l',
                        'm','m','m','m','m','m',
                        'n','n','n','n','n','n',
                        'o','o','o','o','o','o','o','o','o','o','o','o',
                        'p','p','p','p',
                        'q','q',
                        'r','r','r','r','r','r','r',
                        's','s','s','s','s','s','s',
                        't','t','t','t','t','t','t',
                        'u','u','u','u',
                        'v','v','v','v',
                        'z','z',
                        '$','$'};
//VETTORE CON IL PUNTEGGIO DEI GIOCATORI
vector <int> punteggiogiocatori;
//VETTORE CON IL NOME DEI GIOCATORI
vector <string> nomegiocatori;
//VETTORE CON LE LETTERE DEI GIOCATORI IN OGNI TURNO
vector <string> letteregiocatori;
//VETTORE CON LA LETTERA SOSTITUITA DAL JOLLY
vector <char> letterajolly={'$','$'};
//VETTORE CON POSIZIONE DEL PRIMO JOLLY
vector <int> jolly1={17,17};
//VETTORE CON POSIZIONE DEL SECONDO JOLLY
vector <int> jolly2={17,17};
//VETTORE DIZIONARIO CONTENENTE PAROLE DI LUNGHEZZA MAGGIORE A 3
vector <string> paroledizionario;
//VETTORE DIZIONARIO CONTENENTE PAROLE DI LUNGHEZZA 2
vector <string> paroledadue;
//VARIABILE PUNTI AGGIUDICATI AD OGNI TURNO
int punteggioturno;
//ULTIMO GIOCATORE AD AVER INSERITO UNA PAROLA
int ultimoainserire;

//MATRICE RAPPRESENTANTE LE LETTERE SUL CAMPO
string campo [17][17]={"vuota", "vuota", "vuota", "vuota", "vuota", "vuota", "vuota", "vuota", "vuota", "vuota", "vuota", "vuota", "vuota", "vuota", "vuota", "vuota", "vuota",
                       "vuota", "vuota", "vuota", "vuota", "vuota", "vuota", "vuota", "vuota", "vuota", "vuota", "vuota", "vuota", "vuota", "vuota", "vuota", "vuota", "vuota",
                       "vuota", "vuota", "vuota", "vuota", "vuota", "vuota", "vuota", "vuota", "vuota", "vuota", "vuota", "vuota", "vuota", "vuota", "vuota", "vuota", "vuota",
                       "vuota", "vuota", "vuota", "vuota", "vuota", "vuota", "vuota", "vuota", "vuota", "vuota", "vuota", "vuota", "vuota", "vuota", "vuota", "vuota", "vuota",
                       "vuota", "vuota", "vuota", "vuota", "vuota", "vuota", "vuota", "vuota", "vuota", "vuota", "vuota", "vuota", "vuota", "vuota", "vuota", "vuota", "vuota",
                       "vuota", "vuota", "vuota", "vuota", "vuota", "vuota", "vuota", "vuota", "vuota", "vuota", "vuota", "vuota", "vuota", "vuota", "vuota", "vuota", "vuota",
                       "vuota", "vuota", "vuota", "vuota", "vuota", "vuota", "vuota", "vuota", "vuota", "vuota", "vuota", "vuota", "vuota", "vuota", "vuota", "vuota", "vuota",
                       "vuota", "vuota", "vuota", "vuota", "vuota", "vuota", "vuota", "vuota", "vuota", "vuota", "vuota", "vuota", "vuota", "vuota", "vuota", "vuota", "vuota",
                       "vuota", "vuota", "vuota", "vuota", "vuota", "vuota", "vuota", "vuota", "inizio", "vuota", "vuota", "vuota", "vuota", "vuota", "vuota", "vuota", "vuota",
                       "vuota", "vuota", "vuota", "vuota", "vuota", "vuota", "vuota", "vuota", "vuota", "vuota", "vuota", "vuota", "vuota", "vuota", "vuota", "vuota", "vuota",
                       "vuota", "vuota", "vuota", "vuota", "vuota", "vuota", "vuota", "vuota", "vuota", "vuota", "vuota", "vuota", "vuota", "vuota", "vuota", "vuota", "vuota",
                       "vuota", "vuota", "vuota", "vuota", "vuota", "vuota", "vuota", "vuota", "vuota", "vuota", "vuota", "vuota", "vuota", "vuota", "vuota", "vuota", "vuota",
                       "vuota", "vuota", "vuota", "vuota", "vuota", "vuota", "vuota", "vuota", "vuota", "vuota", "vuota", "vuota", "vuota", "vuota", "vuota", "vuota", "vuota",
                       "vuota", "vuota", "vuota", "vuota", "vuota", "vuota", "vuota", "vuota", "vuota", "vuota", "vuota", "vuota", "vuota", "vuota", "vuota", "vuota", "vuota",
                       "vuota", "vuota", "vuota", "vuota", "vuota", "vuota", "vuota", "vuota", "vuota", "vuota", "vuota", "vuota", "vuota", "vuota", "vuota", "vuota", "vuota",
                       "vuota", "vuota", "vuota", "vuota", "vuota", "vuota", "vuota", "vuota", "vuota", "vuota", "vuota", "vuota", "vuota", "vuota", "vuota", "vuota", "vuota",
                       "vuota", "vuota", "vuota", "vuota", "vuota", "vuota", "vuota", "vuota", "vuota", "vuota", "vuota", "vuota", "vuota", "vuota", "vuota", "vuota", "vuota"};

//MATRICE RAPPRESENTANTE IL CAMPO VUOTO
string casellespeciali [17][17]={"3p", "vuota", "vuota", "vuota", "2l", "vuota", "vuota", "vuota", "3p", "vuota", "vuota", "vuota", "2l", "vuota", "vuota", "vuota", "3p",
                                 "vuota", "2p", "vuota", "vuota", "vuota", "vuota", "3l", "vuota", "vuota", "vuota", "3l", "vuota", "vuota", "vuota", "vuota", "2p", "vuota",
                                 "vuota", "vuota", "2p", "vuota", "vuota", "vuota", "vuota", "2l", "vuota", "2l", "vuota", "vuota", "vuota", "vuota", "2p", "vuota", "vuota",
                                 "vuota", "vuota", "vuota", "2p", "vuota", "vuota", "vuota", "vuota", "2l", "vuota", "vuota", "vuota", "vuota", "2p", "vuota", "vuota", "vuota",
                                 "2l", "vuota", "vuota", "vuota", "2p", "vuota", "vuota", "vuota", "vuota", "vuota", "vuota", "vuota", "2p", "vuota", "vuota", "vuota", "2l",
                                 "vuota", "vuota", "vuota", "vuota", "vuota", "2p", "vuota", "vuota", "vuota", "vuota", "vuota", "2p", "vuota", "vuota", "vuota", "vuota", "vuota",
                                 "vuota", "3l", "vuota", "vuota", "vuota", "vuota", "3l", "vuota", "vuota", "vuota", "3l", "vuota", "vuota", "vuota", "vuota", "3l", "vuota",
                                 "vuota", "vuota", "2l", "vuota", "vuota", "vuota", "vuota", "2l", "vuota", "2l", "vuota", "vuota", "vuota", "vuota", "2l", "vuota", "vuota",
                                 "3p", "vuota", "vuota", "2l", "vuota", "vuota", "vuota", "vuota", "vuota", "vuota", "vuota", "vuota", "vuota", "2l", "vuota", "vuota", "3p",
                                 "vuota", "vuota", "2l", "vuota", "vuota", "vuota", "vuota", "2l", "vuota", "2l", "vuota", "vuota", "vuota", "vuota", "2l", "vuota", "vuota",
                                 "vuota", "3l", "vuota", "vuota", "vuota", "vuota", "3l", "vuota", "vuota", "vuota", "3l", "vuota", "vuota", "vuota", "vuota", "3l", "vuota",
                                 "vuota", "vuota", "vuota", "vuota", "vuota", "2p", "vuota", "vuota", "vuota", "vuota", "vuota", "2p", "vuota", "vuota", "vuota", "vuota", "vuota",
                                 "2l", "vuota", "vuota", "vuota", "2p", "vuota", "vuota", "vuota", "vuota", "vuota", "vuota", "vuota", "2p", "vuota", "vuota", "vuota", "2l",
                                 "vuota", "vuota", "vuota", "2p", "vuota", "vuota", "vuota", "vuota", "2l", "vuota", "vuota", "vuota", "vuota", "2p", "vuota", "vuota", "vuota",
                                 "vuota", "vuota", "2p", "vuota", "vuota", "vuota", "vuota", "2l", "vuota", "2l", "vuota", "vuota", "vuota", "vuota", "2p", "vuota", "vuota",
                                 "vuota", "2p", "vuota", "vuota", "vuota", "vuota", "3l", "vuota", "vuota", "vuota", "3l", "vuota", "vuota", "vuota", "vuota", "2p", "vuota",
                                 "3p", "vuota", "vuota", "vuota", "2l", "vuota", "vuota", "vuota", "3p", "vuota", "vuota", "vuota", "2l", "vuota", "vuota", "vuota", "3p"};

//MATRICI PER VERIFICARE IN QUALI CASELLE è POSSIBILE INSERIRE UNA PAROLA
int libereorizzontali [17][15]={0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
                                0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
                                0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
                                0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
                                0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
                                0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
                                0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
                                0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
                                0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
                                0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
                                0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
                                0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
                                0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
                                0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
                                0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
                                0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
                                0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
int libereverticali [15][17]{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
                             0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
                             0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
                             0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
                             0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
                             0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
                             0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
                             0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
                             0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
                             0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
                             0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
                             0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
                             0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
                             0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
                             0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};



void chiedinome(int numerogiocatori);
void distribuzionelettere (int posizione,int &lettererimanenti);
void stampaCampo();
void inserisciparola(int turno,int numerogiocatori);
void trovaposizione (int& pos,char c);
void eliminalettera (int posizione);
int calcolapunteggio (string& parola,int const& x,int const& y,bool &orizzontale,int const& lettereusate,bool const& usoj);
bool controllodizionario (string parola);
void stabiliscivincitore(int numerogiocatori);
bool finegioco(int numerogiocatori,int turno,int lettererimanenti);
void parolamigliore(int turno, int numerogiocatori,vector <string>& parolefattibili);
void visualizzalettere(int posizione);
void sfoltiscidizionario(vector <string>& parolefattibili,int turno);
void stampapunteggio(int numerogiocatori);
void riempidizionario();
void sistemamatrici();
void selector(unsigned short color);


int main()
{


    int turno=0; //indica l'avanzamento dei turni
    int numerogiocatori=0; //indica il numero di giocatori
    int lettererimanenti=130; //indica le lettere rimanent nel gioco
    bool fine; //indica se la partita è finita
    bool carattere=false;



    srand (time (0));
    // CHIEDERE NUMERO GIOCATORI
    do{
        string ingresso;
        carattere=false;
        numerogiocatori=0;
        selector(79);
        cout<< "inserisi il numero di giocatori (2, 3 o 4)" <<endl;
        selector(7);
        cin >> ingresso;
        for (size_t i=0;i<ingresso.size();++i) //viene controllato che ciò che si inserisce sia un numero
        {
            if (ingresso[i]>'0' && ingresso[i]<'9' )
                numerogiocatori=numerogiocatori*10+(ingresso[i]-'0');
            else{

                carattere=true;
                break;
            }
        }


    }while (numerogiocatori<2 || numerogiocatori>4 || carattere);

    //CHIEDERE NOME GIOCATORI IN BASE AL NUMERO
    chiedinome(numerogiocatori);
    //STAMPARE CAMPO VUOTO PER LA PRIMA VOLTA
    stampaCampo();
    //RIEMPIRE VETTORE DIZIONARIO
    riempidizionario();
    //PRIMA DISTRIBUZIONE LETTERE AI GIOCAOTRI
    for (int l=0;l<numerogiocatori;++l){
        distribuzionelettere ((l),lettererimanenti);}

    do {

        string passa=""; //per passare il turno quando le lettere sono finite

        string suggerimento="";

        sistemamatrici(); //consente di sapere in quali caselle è possibile inserire una parola (per il suggerimento)

        vector <string> parolefattibili; //vettore di parole che l'utente può comporre con le sue lettere (per suggerimento)
        sfoltiscidizionario(parolefattibili,turno%numerogiocatori); //consente di sapere quali parole il giocatore puù comporre con le sue lettere (per il suggerimento)

        visualizzalettere(turno%numerogiocatori); //stampa delle lettere del giocatore


        for (size_t i=0;i<letteregiocatori[turno%numerogiocatori].size();++i){ //se il giocatore possiete il jolly
            string lettere=letteregiocatori[turno%numerogiocatori];            //le parole fattibili diventano tutte quelle
            if (lettere[i]=='$')                                               //del dizionario
            {
                parolefattibili=paroledizionario;
                break;
            }
        }

        do{
            suggerimento="";
            selector(79);
            cout << "Vuoi usufruire del suggerimento? (si o no)" << endl;
            selector(7);
            cin >> suggerimento;

        }while(suggerimento!="si" && suggerimento!="no");

        if (suggerimento=="si"){
            //SUGGERIMENTO DELLA PAROLA MIGLIORE
            parolamigliore(turno, numerogiocatori,parolefattibili);
        }

        //SE LE LETTERE SONO FINITE POSSIBILITA' DI PASSARE IL TURNO
        if (lettererimanenti==0)
        {
            do{
                selector(79);
                cout << "il sacchetto e' vuoto, vuoi passare il turno? (si o no)" << endl;
                selector(7);
                cin >> passa;
            } while (passa!="si" && passa!="no");

        }

        if (passa!="si")
        {
            //INSERIMENTO PAROLA NEL CAMPO
            inserisciparola (turno,numerogiocatori);

            //SI SALVA L'ULTIMO CHE HA INSERITO LA PAROLA
            ultimoainserire=turno%numerogiocatori;

            system("cls"); //"pulizia" dello schermo

            stampapunteggio(numerogiocatori); //stampa del punteggio di tutti i giocatori

            //STAMPA DEL CAMPO
            stampaCampo();
        }


        //VERIFICA SE UN GIOCATORE HA FINITO LE PROPRIE LETTERE QUANDO IL "SACCHETTO" E' VUOTO
        fine=finegioco(numerogiocatori,turno,lettererimanenti);


        distribuzionelettere(turno%numerogiocatori,lettererimanenti); //distribuzione delle lettere al giocatore a fine turno


        ++turno; // avanzamento del turno



    } while (!fine);

    //STABILISCE IL VINCITORE DELLA PARTITA
    stabiliscivincitore(numerogiocatori);




    return 0;
}



void chiedinome(int numerogiocatori)
{
    //INSERIMENTO NOMI IN BASE AL NUMERO DEI GIOCATORI NEL VETTORE NOMEGIOCATORI
    string nome;
    for (int i=0; i<numerogiocatori; ++i)
    {
        selector(79);
        cout << "inserisci il nome del giocatore numero " << i+1 <<endl;
        selector(7);
        do{
            nome="";
            getline(cin,nome);
        }while(nome=="");
        nomegiocatori.push_back(nome);
        punteggiogiocatori.push_back(0); //il vettore viene ampliato a seconda del numero di giocatori
        letteregiocatori.push_back(""); //il vettore viene ampliato a seconda del numero di giocatori

    }
}

void distribuzionelettere (int posizione,int &lettererimanenti)
{

    int lettera;
    int numero=letteregiocatori[posizione].size();

    for (int j=0; j<8-numero; ++j)
    {
        if (lettererimanenti==0) // se non rimangono più lettere non è più possibile distribuirne
        {
            break;
        }
        lettera=rand()%lettererimanenti; //generazione di un numero casuale tra 0 e lettererimanenti per "pescare" una lettera casuale
        --lettererimanenti; //decremento lettere rimanenti
        letteregiocatori[posizione]=letteregiocatori[posizione]+alfabeto[lettera];//aggiunta lettera "pescata" tra le lettere del giocatore
        eliminalettera (lettera);//eliminazione lettera dal "sacchetto"
    }

}

void visualizzalettere(int posizione)
{
    //STAMPA DELLE LETTERE DEL GIOCATORE CORRENTE
    selector(79);
    cout << nomegiocatori[posizione] << " le tue lettere sono : " << letteregiocatori[posizione] << endl;
    string lettere=letteregiocatori[posizione];
    string risposta;
    string confronto;

    if (jolly1[0]!=17) //verifica se il giocatore può prendere il jolly presente sul campo
    {
        int j=jolly1[0];//posizione del primo jolly
        int k=jolly1[1];
        for (size_t h=0; h<lettere.size();++h)
        {
            confronto=lettere[h];
            if (confronto==campo[j][k])//se il giocatore possiede le stessa lettera rappresentata dal jolly, può prendere esso
            {
                do{
                    selector(79);
                    cout<<"vuoi scambiare la tua lettera " << confronto <<" con il jolly? (si o no)"<<endl;
                    selector(7);
                    cin >>risposta;
                } while (risposta!="si" && risposta!="no");
                if (risposta=="si") // se vuole prendere il jolly, la sua lettera viene scambata con esso
                {
                    lettere[h]='$';
                    jolly1[0]=17;//il jolly viene messo in una posizione esterna al campo per indicare che non è presente nello stesso
                    jolly1[1]=17;
                    break;
                }
                else if (risposta=="no"){
                    break;
                }

            }
        }
        letteregiocatori[posizione]=lettere;
        if (risposta=="si"){
            selector(79);
            cout << nomegiocatori[posizione] << " le tue lettere ora sono : " << letteregiocatori[posizione] << endl;
        }
    }
    risposta="";
    confronto="";
    if (jolly2[0]!=17) //verifica se il giocatore può prendere il jolly presente sul campo
    {
        int j=jolly2[0];//posizione del secondo jolly
        int k=jolly2[1];
        for (size_t h=0; h<lettere.size();++h)
        {
            confronto=lettere[h];
            if (confronto==campo[j][k])//se il giocatore possiede le stessa lettera rappresentata dal jolly, può prendere esso
            {

                do{
                    selector(79);
                    cout<<"vuoi scambiare la tua lettera " <<confronto <<" con il jolly? (si o no)"<<endl;
                    selector(7);
                    cin >>risposta;
                } while (risposta!="si" && risposta!="no");
                if (risposta=="si")// se vuole prendere il jolly, la sua lettera viene scambata con esso
                {
                    lettere[h]='$';
                    jolly2[0]=17;//il jolly viene messo in una posizione esterna al campo per indicare che non è presente nello stesso
                    jolly2[1]=17;
                    break;
                }
                else if (risposta=="no"){
                    break;
                }
            }

        }

        letteregiocatori[posizione]=lettere;
        if (risposta=="si"){ // se il giocatore ha preso il jolly si ristampano le sue lettere
            selector(79);
            cout << nomegiocatori[posizione] << " le tue lettere ora sono : " << letteregiocatori[posizione] << endl;
        }
    }
    selector(7);
}

void stampaCampo () {
    cout << setw(3) << " ";
    for (int i=0;i<17;++i) //stampa dei numeri di colonna
    {
        cout << setw(3) << i;
    }
    cout << endl;

    for (int j=0;j<17;++j)
    {
        selector (7);
        cout << setw(3) << j;// stampa dei numeri di riga
        for (int k=0;k<17;++k)
        {
            if (casellespeciali[j][k]=="vuota")//se la cella è vuota rimane nera
            {
                selector (15);

            }
            else if (casellespeciali [j][k]=="3p")//la cella 3p è rossa
            {
                selector(79);
            }
            else if (casellespeciali[j][k]=="3l")//la cella 3l è blu
            {
                selector(31);
            }
            else if (casellespeciali[j][k]=="2p")//la cella 2p è verde
            {
                selector(47);
            }
            else if (casellespeciali[j][k]=="2l")//la cella 2l è grigia
            {
                selector(143);
            }
            if (campo[j][k]=="vuota")
                cout<<"   ";
            else if (campo[j][k]=="inizio")//nella cella di inizio vengono stampati dei calcelletti per connotarla
                cout<<"###";
            else if((j==jolly1[0] && k==jolly1[1]) || (j==jolly2[0] && k==jolly2[1]))//la lettera jolly è stampata in rosso
            {
                //NELLA CENNA IN CUI E' PRESENTE IL JOLLY VIENE UTILIZZATO UN LAYOUT CON LO SFONDO DELLA CELLA CORRISPONDENTE E IL TESTO ROSSO
                if (casellespeciali[j][k]=="vuota")
                {
                    selector(12);
                    cout<<setw(3)<<campo[j][k];
                }
                else if (casellespeciali[j][k]=="2p")
                {
                    selector(44);
                    cout<<setw(3)<<campo[j][k];
                }
                else if (casellespeciali[j][k]=="2l")
                {
                    selector(140);
                    cout<<setw(3)<<campo[j][k];
                }
                else if (casellespeciali[j][k]=="3p")
                {
                    selector(76);
                    cout<<setw(3)<<campo[j][k];
                }
                else if (casellespeciali[j][k]=="3l")
                {
                    selector(28);
                    cout<<setw(3)<<campo[j][k];
                }
            }
            else
                cout<<setw(3)<<campo[j][k];

        }
        cout<<endl;

    }
    cout<<endl;
    selector (7);
    cout << "legenda : " << endl; //stampa della legenda

    selector(15);
    cout<<setw(3)<<" ";
    selector (7);
    cout << " vuota"<< endl;
    selector(47);
    cout<<setw(3)<<" ";
    selector (7);
    cout << " 2p"<< endl;
    selector(143);
    cout<<setw(3)<<" ";
    selector (7);
    cout << " 2l"<< endl;
    selector(79);
    cout<<setw(3)<<" ";
    selector (7);
    cout << " 3p"<< endl;
    selector(31);
    cout<<setw(3)<<" ";
    selector (7);
    cout << " 3l"<< endl;
    selector(12);
    cout << setw(3) << "$";
    selector(7);
    cout << " jolly" << endl;
    cout << endl;

    selector(7);

}


void inserisciparola (int turno,int numerogiocatori)
{


    int x=0;//coordinate inserimento parola turno 0
    int y=0;
    int rp=0;
    int cp=0;

    int partenza=0;//conteggio cella di partenza per parole formate

    string parola;//parola inserita

    string lettere=letteregiocatori[turno%numerogiocatori];//variabili per la modifica e l'utilizzo delle
    string lettere2;                                       //lettere del giocatore
    string intera=lettere;
    string intera2=lettere;

    string direzione;//direzione di inserimento della parola

    string formata="";//gestione parole formate a seguito dell'inserimento della propria

    string ingresso1;//stringhe per la gestione e il controllo dell'inserimento delle coordinate
    string ingresso2;

    string intera3;//variabie per gestione della parola

    int lettereusate=lettere.size();//numero di lettere usate dal giocatore (per punteggio)

    bool controllo=true; //variabili booleane per la gestione dei controlli
    bool orizzontale=true;
    bool interseca=false;
    bool corrispondenza=true;
    bool contorno=false;
    bool carattere=false;
    bool furbo=false;
    bool usoj=false;

    int usate=0;//numero di lettere usate (per controllo)

    int jolly=0;//numero di jolly




    if (turno==0)
    {



        do{
            usoj=false;           //nel caso in cui il ciclo si ripeta
            if (controllo==false) //le variabili vengono poste al valore iniziale

                lettere=intera2;
            controllo = true;
            do{                  //il giocatore deve inserire la parola, il ciclo si ripete finchè la parola valida
                selector(79);
                cout << "inserisci la parola scelta (deve essere composta da almeno tre lettere per essere considerata nel punteggio)" << endl;
                selector(7);
                cin >> parola;
                for (size_t i=0;i<parola.size();++i) //se viene inserito un numero la parola viene settata a stringa vuota per evitare che il programma vada in loop
                {
                    if (parola[i]>='0' && parola[i]<='9')
                    {
                        parola="";
                    }
                }
                intera=parola;
                intera3=parola;
            } while (!controllodizionario(parola) || parola.size()<1);

            for (size_t p=0;p<lettere.size();++p) //vengono contati i jolly posseduti dal giocatore corrente
            {
                if (lettere[p]=='$')
                    ++jolly;
            }


            //CONTROLLO DELLE LETTERE NECESSARIE A COMPORRE LA PAROLA
            for (size_t k =0;k<parola.size();++k)
            {
                if (lettere.size()==0) //se il giocatore non ha più lettere ma la parola non è finita, vuol dire che non ha le lettere necessarie per comporla
                {
                    controllo=false;
                    selector(79);
                    cout << "hai usato una lettera che non possiedi!" << endl;
                    selector(7);
                    letteregiocatori[turno%numerogiocatori]=intera2;
                    break;
                }
                for (size_t j =0;j<lettere.size();++j)
                {
                    if (parola[k]==lettere[j]) //le lettere necessarie a comporre la parola vengono tolte da quelle che possiede il giocatore
                    {
                        for (size_t w=0;w<lettere.size();++w)
                        {

                            if (w!=j) //se gli indici sono uguali la lettera corrispondente non viene copiata
                            {
                                lettere2=lettere2+lettere[w];

                            }


                        }

                        lettere=lettere2;

                        letteregiocatori[turno]=lettere;//le lettere del giocatore vengono aggiornate togliendo quelle necessarie per comporre la parola
                        lettere2="";
                        break;
                    }

                    else if (j==lettere.size()-1) //se la lettera che si cerca non è ancora stata trovata e
                    {                             //si è all'ultima posizione delle lettere del giocatore
                        if (jolly>0)              //allora si guarda se il giocatore ha un jolly
                        {
                            --jolly;
                            usoj=true;
                            parola[k]='$';
                            for (size_t l=0;l<lettere.size();++l)
                            {
                                if (lettere[l]!='$')
                                {
                                    lettere2=lettere2+lettere[l];


                                }

                            }

                            lettere=lettere2;

                            letteregiocatori[turno]=lettere;
                            lettere2="";


                        }
                        else //se non ha il jolly vuol dire che non ha le lettere necessarie per comporre la parola
                        {
                            controllo = false;
                            selector(79);
                            cout << "hai usato una lettera che non possiedi!" << endl;
                            selector(7);
                            letteregiocatori[turno%numerogiocatori]=intera2; //le lettere del giocatore vengono reimpostate
                        }
                    }

                }

            }


            if (controllo==true){
                do {
                    controllo=true;

                    do { //se il controllo è andato a buon fine si chiedono le coordinate di inserimento della parola
                        x=0;
                        y=0;
                        carattere=false;
                        selector(79);
                        cout << "Da quale casella vuoi partire per inserire la parola (devi passare obbligatoriamente dal centro)" << endl;
                        cout << "inserisci la riga" << endl;
                        selector(7);
                        cin >> ingresso1;
                        for (size_t i=0;i<ingresso1.size();++i) //viene controllato che ciò che si inserisce sia un numero
                        {
                            if (ingresso1[i]>='0' && ingresso1[i]<='9' )
                                x=x*10+(ingresso1[i]-'0');
                            else carattere=true;
                        }
                        selector(79);
                        cout << "inserisci colonna" << endl;
                        selector(7);
                        cin >> ingresso2;
                        for (size_t i=0;i<ingresso2.size();++i) //viene controllato che ciò che si inserisce sia un numero
                        {
                            if (ingresso2[i]>='0' && ingresso2[i]<='9' )
                                y=y*10+(ingresso2[i]-'0');
                            else carattere=true;
                        }
                    } while (carattere || x<0 || x>16 || y<0 || y>16); //si assicura che le coordinate siano interne al campo


                    if (y==8)
                    {
                        if (x==8) //se la cella di partenza è il centro è necessario chiedere la direzione di inserimento
                        {
                            do{
                                selector(79);
                                cout << "vuoi inserirla in verticale o in orizzontale ?" << endl;
                                selector(7);
                                cin >> direzione;
                                if (direzione == "orizzontale")
                                    orizzontale=true;
                                else
                                    orizzontale=false;
                            } while (direzione!="orizzontale" && direzione!="verticale"); //si assicura che l'utente inserisca una delle due possibili direzioni
                        }
                        else if (x+parola.size()<=8 || x>8) //verifica che la parola passi per il centro
                        {
                            controllo=false;
                            selector(79);
                            cout << "la parola non passa per il centro " << endl;
                            selector(7);
                        }

                    }
                    else if (x==8) { //verifica che la parola passi per il centro
                        if ( y+parola.size()<=8 || y>8)
                        {
                            controllo=false;
                            selector(79);
                            cout << "la parola non passa per il centro " << endl;
                            selector(7);
                        }}
                    else{
                        selector(79);
                        cout << "la parola non passa per il centro " << endl;
                        selector(7);

                        controllo = false; //se nessuna delle due coordinate è 8 il controllo non viene superato
                    }

                } while (controllo==false);
            }
        } while (controllo==false);

        for (size_t w=0;w<parola.size();++w) //se la parola ha passato tutti i controlli, essa viene inserita nel campo
        {

            if (x==8 && orizzontale)
            {
                campo[x][y+w]=intera3[w];
            }
            else
            {
                orizzontale=false;
                campo[x+w][y]=intera3[w];
            }
            if (parola[w]=='$')
            {
                if (jolly1[0]==17)               //in caso venga usato il jolly, le coordinate del jolly vengono settate alla posizione del jolly usato
                {
                    if (x==8 && orizzontale)
                    {
                        jolly1[0]=x;
                        jolly1[1]=y+w;
                    }
                    else
                    {
                        jolly1[0]=x+w;
                        jolly1[1]=y;
                    }
                }
                else
                {
                    if (x==8 && orizzontale)
                    {
                        jolly2[0]=x;
                        jolly2[1]=y+w;
                    }
                    else
                    {
                        jolly2[0]=x+w;
                        jolly2[1]=y;
                    }
                }
            }
        }
        lettereusate=lettereusate-lettere.size(); //vengono calcolate le lettere usate
        punteggioturno=0;
        if (intera.size()>=3){
            punteggioturno=calcolapunteggio (intera,x,y,orizzontale,lettereusate,usoj); //calcolo del punteggio ottenuto
            punteggiogiocatori[turno%numerogiocatori]+=punteggioturno; //aggiornamento del punteggio del giocatore

        }
    }

    else
    {
        string parola2="";




        do{
            do{
                do{
                    do{
                        punteggioturno=0;
                        usate=0;                       //nel caso in cui i cicli vengano ripetuti
                        usoj=false;                    //le variabili vengono poste ai valori iniziali
                        contorno=false;
                        lettere=intera2;
                        if (controllo==false)
                            lettere=intera2;
                        controllo = true;
                        furbo=false;

                        do{   //viene chiesta la parola che si vuole inserire
                            selector(79);
                            cout << "inserisci la parola scelta (deve essere composta da almeno tre lettere per essere considerata nel punteggio)" << endl;
                            selector(7);
                            cin >> parola;
                            for (size_t i=0;i<parola.size();++i) //si controlla che non si inseriscano numeri che potrebbero dare problemi al programma
                            {
                                if (parola[i]>='0' && parola[i]<='9')
                                {
                                    parola="";
                                }
                            }
                            intera=parola;
                            intera3=parola;
                        } while (!controllodizionario(parola) || parola.size()<2); //la parola deve essere contenuta nel dizionario e deve avere almeno lunghezza 2

                        corrispondenza=true;
                        interseca=false;
                        parola=intera;
                        do { //se la parola è corretta vengono chieste le coordinate di inserimento
                            rp=0;
                            cp=0;
                            carattere=false;
                            selector(79);
                            cout << "Da quale casella vuoi partire ?" << endl;
                            cout << "inserisci la riga" << endl;
                            selector(7);
                            cin >> ingresso1;
                            for (size_t i=0;i<ingresso1.size();++i) //si controlla che ciò che si inserisce sono solo numeri
                            {
                                if (ingresso1[i]>='0' && ingresso1[i]<='9' )
                                    rp=rp*10+(ingresso1[i]-'0');
                                else carattere=true;
                            }
                            selector(79);
                            cout << "inserisci colonna" << endl;
                            selector(7);
                            cin >> ingresso2;
                            for (size_t i=0;i<ingresso2.size();++i) //si controlla che ciò che si inserisce sono solo numeri
                            {
                                if (ingresso2[i]>='0' && ingresso2[i]<='9' )
                                    cp=cp*10+(ingresso2[i]-'0');
                                else carattere=true;
                            }
                        } while (carattere || rp<0 || rp>16 || cp<0 || cp>16); //si controlla che le coordinate siano contenute nel campo e che siano  composte solo da numeri

                        do{ //si chiede la direzione di inserimento
                            selector(79);
                            cout << "vuoi inserirla in verticale o in orizzontale ?" << endl;
                            selector(7);
                            cin >> direzione;
                            if (direzione == "orizzontale")
                                orizzontale=true;
                            else
                                orizzontale=false;

                        }while (direzione!="orizzontale" && direzione!="verticale"); //si controlla che venga inserita una delle due opzioni

                        if ((orizzontale && cp+parola.size()>17) || (!orizzontale && rp+parola.size()>17)) //si controlla che la parola non esca dal campo
                        {
                            selector(79);
                            cout << "la parola esce dal campo!" << endl;
                            selector(7);
                        }


                    }while ((orizzontale && cp+parola.size()>17) || (!orizzontale && rp+parola.size()>17)); //finchè la parola esce dal campo, il cico si ripete
                    if (orizzontale)
                    {
                        if ((cp>0 && campo[rp][cp-1]!="vuota") || (cp+intera.size()<=16 && campo[rp][cp+intera.size()]!="vuota")) //se nella cella subito prima, e in quella subito dopo
                            contorno=true;                                                                                        //la parola, è presente una lettera, non è possibile inserire la parola

                        else //si controlla se si formano parole a seguito dell'inserimento, in caso affermativo si controlla la loro validita
                        {
                            for (size_t u=0;u<intera.size();++u) //per navigare all'interno del campo
                            {
                                if (cp+(int)u>=0 && cp+(int)u<17) //controlla che ci si trovi all'interno del campo
                                {
                                    if (campo[rp][cp+u]=="vuota")
                                    {
                                        if ((rp>1 && campo[rp-1][cp+u]!="vuota" && campo[rp-2][cp+u]!="vuota") ||              //controlla se sono presenti lettere intorno alla lettera
                                                (rp>0 && rp<16 && campo[rp-1][cp+u]!="vuota" && campo[rp+1][cp+u]!="vuota") || //se esse sono presenti e formano una parola di almeno 3 lettere
                                                (rp<15 && campo[rp+1][cp+u]!="vuota" && campo[rp+2][cp+u]!="vuota"))           //bisogna controllare che la parola formata sia corretta
                                        {
                                            int k=1;
                                            partenza=rp;
                                            while (rp-k>=0 && rp-k<=16 && campo[rp-k][cp+u]!="vuota")  //si cerca da dove inizia la parola che si è formata
                                            {
                                                --partenza;
                                                ++k;
                                            }
                                            k=0;
                                            while (partenza+k<17 && (partenza+k==rp || campo[partenza+k][cp+u]!="vuota"))  //attraverso concatenazione di caratteri si legge la parola formata
                                            {
                                                if (partenza+k==rp)  //se la lettera considerata è sulla stessa riga della parola inserita, essa appartiene alla parola da inserire
                                                {
                                                    formata=formata+intera[u];
                                                }
                                                else //altrimenti la lettera è presente sul campo e va letta da esso
                                                {

                                                    formata=formata+campo[partenza+k][cp+u];
                                                }
                                                ++k;
                                            }
                                            if (!controllodizionario(formata)) //si controlla che la parola formata sia contenuta all'interno del dizionario
                                                contorno=true;
                                            else
                                                punteggioturno+=calcolapunteggio(formata,partenza,cp+u,orizzontale,1,true); //se tutti i controlli sono andati a buon fine
                                            formata="";                                                                                                //si aggiorna il punteggio del giocatore corrente
                                        }
                                    }
                                }}
                        }
                    }

                    if (!orizzontale) //caso di parola verticale
                    {
                        if ((rp>0 && campo[rp-1][cp]!="vuota") || (rp+intera.size()<=16 && campo[rp+intera.size()][cp]!="vuota")) //se nella cella subito prima, e in quella subito dopo
                            contorno=true;                                                                                        //la parola, è presente una lettera, non è possibile inserire la parola


                        else //si controlla se si formano parole a seguito dell'inserimento, in caso affermativo si controlla la loro validita
                        {
                            for (size_t u=0;u<intera.size();++u) //per navigare all'interno del campo
                            {
                                if (rp+(int)u>=0 && rp+(int)u<17) //controlla che ci si trovi all'interno del campo
                                {
                                    if (campo[rp+u][cp]=="vuota")
                                    {
                                        if ((cp>1 && campo[rp+u][cp-1]!="vuota" && campo[rp+u][cp-2]!="vuota") ||               //controlla se sono presenti lettere intorno alla lettera
                                                (cp>0 && cp<16 && campo[rp+u][cp-1]!="vuota" && campo[rp+u][cp+1]!="vuota") ||  //se esse sono presenti e formano una parola di almeno 3 lettere
                                                (cp<15 && campo[rp+u][cp+1]!="vuota" && campo[rp+u][cp+2]!="vuota"))            //bisogna controllare che la parola formata sia corretta
                                        {
                                            int k=1;
                                            partenza=cp;
                                            while (cp-k>=0 && cp-k<=16 && campo[rp+u][cp-k]!="vuota") //si cerca da dove inizia la parola che si è formata
                                            {
                                                --partenza;
                                                ++k;
                                            }
                                            k=0;
                                            while (partenza+k<17 && (partenza+k==cp || campo[rp+u][partenza+k]!="vuota")) //attraverso concatenazione di caratteri si legge la parola formata
                                            {
                                                if (partenza+k==cp) //se la lettera considerata è sulla stessa colonna della parola inserita, essa appartiene alla parola da inserire
                                                {
                                                    formata=formata+intera[u];
                                                }
                                                else //altrimenti la lettera è presente sul campo e va letta da esso
                                                {
                                                    formata=formata+campo[rp+u][partenza+k];
                                                }
                                                ++k;
                                            }
                                            if (!controllodizionario(formata)) //si controlla che la parola formata sia contenuta all'interno del dizionario
                                                contorno=true;
                                            else
                                                punteggioturno+=calcolapunteggio(formata,rp+u,partenza,orizzontale,1,true); //se tutti i controlli sono andati a buon fine
                                            formata="";                                                                                                //si aggiorna il punteggio del giocatore corrente
                                        }
                                    }
                                }}
                        }
                    }


                    for (size_t r=0; r<parola.size(); ++r) //si controlla che la parola da inserire intersechi almeno una di quelle già presenti sul campo
                    {
                        if (orizzontale==true && campo[rp][cp+r]>="a" && campo[rp][cp+r]<="z" && campo[rp][cp+r]!="vuota") //caso di inserimento orizzontale
                        {
                            interseca=true;
                        }
                        else if(orizzontale==false && campo[rp+r][cp]>="a" && campo[rp+r][cp]<="z" && campo[rp+r][cp]!="vuota") //caso di iserimento verticale
                        {
                            interseca=true;
                        }
                    }
                    if (interseca==false){ //se non interseca viene stampato un avviso
                        selector(79);
                        cout <<"la parola deve intersecare alemeno una lettera gia' presente sul campo" <<endl;
                        selector(7);
                    }

                }while(interseca==false); //se non interseca il ciclo ricomincia



                vector<string> confronto;
                for (size_t f=0; f<parola.size(); ++f)  //viene creato un vettore che permette di convertire un carattere in stringa e quindi di fare il confronto
                {
                    confronto.push_back("a");
                    confronto[f]=parola[f];
                }

                for (size_t w=0;w<parola.size();++w) //se è presente almeno un'intersezione si cotrolla che essa sia corretta
                {                                    //viene anche controllato che l'utente usi almeno una delle sue lettere

                    if (orizzontale==true && campo[rp][cp+w]!="vuota") //caso orizzontale
                    {
                        if (confronto[w]!=campo[rp][cp+w])
                            corrispondenza=false;
                        else
                            parola2=parola2+'#';
                    }
                    else if (orizzontale==false && campo[rp+w][cp]!="vuota") //caso verticale
                    {
                        if (confronto[w]!=campo[rp+w][cp])
                            corrispondenza=false;
                        else
                            parola2=parola2+'#';
                    }
                    else if (orizzontale==true && campo[rp][cp+w]=="vuota") //caso orizzontale con assenza di intersezione
                    {
                        parola2=parola2+parola[w];
                        ++usate;
                    }
                    else if (orizzontale==false && campo[rp+w][cp]=="vuota") //caso verticale con assenza di intersezione
                    {
                        parola2=parola2+parola[w];
                        ++usate;
                    }


                }

                if (usate==0) //se non sono state usate lettere proprie viene stampato un avviso
                {
                    selector(79);
                    cout<<"devi usare almeno una delle tue lettere"<<endl;
                    selector(7);
                    furbo=true;
                }
                if (!corrispondenza){ //se l'intersezione non è corretta viene stampato un avviso
                    selector(79);
                    cout << "le lettere sono disposte nel modo sbagliato" <<endl;
                    selector(7);
                }

                parola=parola2;
                parola2="";

            }while (!corrispondenza || furbo); //se non sono state usate parole proprie o l'intersezione non è corretta il ciclo ricomincia

            for (size_t p=0;p<lettere.size();++p) //vengono contati i jolly posseduti dal giocatore
            {
                if (lettere[p]=='$')
                    ++jolly;
            }

            //SI CONTROLLA CHE IL GIOCATORE ABBIA LE LETTERE NECESSARIE PER COMPORRE LA PAROLA
            for (size_t k =0;k<parola.size();++k)
            {
                if (parola[k]!='#')
                {
                    if (lettere.size()==0) //se non ci sono più lettere del giocatore da controllare, ma la parola non è finita,
                    {                      //allora il giocatore non possiede le lettere necessarie per comporre la parola
                        controllo=false;
                        selector(79);
                        cout << "hai usato una lettera che non possiedi!" << endl;
                        selector(7);
                        letteregiocatori[turno%numerogiocatori]=intera2;
                        break;
                    }
                    for (size_t j =0;j<lettere.size();++j)
                    {
                        if (parola[k]==lettere[j]) //quando si trova la lettera cercata tra le lettere del giocatore la si toglie da esse
                        {
                            for (size_t w=0;w<lettere.size();++w)
                            {

                                if (w!=j) //se gli indici sono uguali, la lettera in quella posizione non viene copiata perche deve essere tolta
                                {
                                    lettere2=lettere2+lettere[w];

                                }


                            }

                            lettere=lettere2;

                            letteregiocatori[turno%numerogiocatori]=lettere; //vengono aggiornate le lettere del giocatore
                            lettere2="";
                            break;
                        }
                        else if (j==lettere.size()-1) //se la lettera cercata non è ancora stata trovata e si è in ultima posizione
                        {
                            if (jolly>0) //si verifica se il giocatore ha un jolly (in caso affermativo si usa esso)
                            {
                                --jolly;
                                parola[k]='$';
                                intera[k]='$';
                                usoj=true;
                                for (size_t l=0;l<lettere.size();++l) //viene tolto il jolly se lo si usa
                                {
                                    if (lettere[l]!='$') //se è il jolly usato lo si toglie
                                    {
                                        lettere2=lettere2+lettere[l];


                                    }
                                    else //il resto viene copiato
                                    {
                                        for (size_t m=l+1;m<lettere.size();++m)
                                        {
                                            lettere2=lettere2+lettere[m];
                                        }
                                        break;
                                    }

                                }

                                lettere=lettere2;

                                letteregiocatori[turno%numerogiocatori]=lettere; //vengono aggiornate dle lettere del giocatore
                                lettere2="";

                            }
                            else //se non possiede il jolly non ha le lettere necessarie per comporre le parole
                            {
                                controllo = false;
                                selector(79);
                                cout << "hai usato una lettera che non possiedi!" << endl;
                                selector(7);
                                letteregiocatori[turno%numerogiocatori]=intera2;
                            }
                        }

                    }
                }
            }



            if (contorno) //se inserendo la parola se ne formano altre non valide, viene stampato un avviso e il ciclo ricomincia
            {
                selector(79);
                cout<<"ci sono parole errate che si formano"<<endl;
                selector(7);
                letteregiocatori[turno%numerogiocatori]=intera2;
            }



        } while (controllo==false || contorno);

        for (size_t n=0; n<intera.size(); ++n) //dopo aver passato tutti i controlli la parola viene inserita nel campo
        {
            if (orizzontale==true && campo[rp][cp+n]=="vuota")
                campo[rp][cp+n]=intera3[n];
            else if (orizzontale==false && campo[rp+n][cp]=="vuota")
                campo[rp+n][cp]=intera3[n];
            if (intera[n]=='$') //se viene usato un jolly, viene aggiornato il vettore corrispondente
            {
                if (jolly1[0]==17)
                {
                    if (orizzontale)
                    {
                        jolly1[0]=rp;
                        jolly1[1]=cp+n;
                    }
                    else
                    {
                        jolly1[0]=rp+n;
                        jolly1[1]=cp;
                    }
                }
                else
                {
                    if (orizzontale)
                    {
                        jolly2[0]=rp;
                        jolly2[1]=cp+n;
                    }
                    else
                    {
                        jolly2[0]=rp+n;
                        jolly2[1]=cp;
                    }
                }
            }
        }


        lettereusate=lettereusate-lettere.size(); //si calcolano le lettere usate dall'utente
        if (intera3.size()>=3){  //se la parola ha lunghezza maggiore o uguale a 3 viene considerata nel punteggio
            punteggioturno+=calcolapunteggio (intera3,rp,cp,orizzontale,lettereusate,usoj); //si calcola il punteggio acquisito
            punteggiogiocatori[turno%numerogiocatori]+=punteggioturno; //si aggiorna il punteggio del giocatore
        }


    }


}


void eliminalettera (int posizione){

    vector <char> stringa2;
    for (size_t w=0;w<alfabeto.size();++w)         //copia tutte le lettere del sacchetto
    {                                              //in un altro vector di caratteri
        //tranne la lettera appena utilizzata
        if ((int)w!=posizione)
        {
            stringa2.push_back(alfabeto[w]);
        }



    }

    alfabeto=stringa2;            //aggiorna quindi il sacchetto


}

int calcolapunteggio (string& parola,int const& x,int const& y,bool &orizzontale,int const& lettereusate,bool const& usoj)
{
    int posizione=0;
    int punteggio=0;
    int noperlettere=0;
    int differenza=0;
    int dp=0;
    int tp=0;


    for (size_t i=0;i<parola.size();++i)                        //si apre un ciclo for che scorre tutte le lettere della parola
    {                                                           //calcola la posizione della lettera per il vector di interi valorelettere
        posizione=parola[i]-'a';                                //calcola il punteggio della parola senza bonus, della differenza tra
        //le lettere che sono su "2L" o "3L" e il loro valore, e il numero di "2P" e "3P"
        if (orizzontale)                                        //che vengono "schiacciati"
        {
            if (casellespeciali[x][y+i]=="vuota")
            {
                noperlettere +=valorelettere[posizione];
            }
            else if (casellespeciali[x][y+i]=="2l")
            {
                differenza+=valorelettere[posizione];
                noperlettere +=valorelettere[posizione];
            }
            else if (casellespeciali[x][y+i]=="3l")
            {
                differenza+=valorelettere[posizione]*2;
                noperlettere +=valorelettere[posizione];
            }
            else if (casellespeciali[x][y+i]=="2p")
            {
                noperlettere +=valorelettere[posizione];
                ++dp;
            }
            else if (casellespeciali[x][y+i]=="3p")
            {
                noperlettere +=valorelettere[posizione];
                ++tp;
            }
        }

        else
        {
            if (casellespeciali[x+i][y]=="vuota")
            {
                noperlettere+=valorelettere[posizione];
            }

            else if (casellespeciali[x+i][y]=="2l")
            {
                differenza+=valorelettere[posizione];
                noperlettere +=valorelettere[posizione];
            }

            else if (casellespeciali[x+i][y]=="3l")
            {
                differenza+=valorelettere[posizione]*2;
                noperlettere +=valorelettere[posizione];
            }

            else if (casellespeciali[x+i][y]=="2p")
            {
                noperlettere +=valorelettere[posizione];
                ++dp;
            }

            else if (casellespeciali[x+i][y]=="3p")
            {
                noperlettere +=valorelettere[posizione];
                ++tp;
            }
        }

    }

    if (dp!=0)
        noperlettere=noperlettere*2*dp;
    else if (tp!=0)
        noperlettere=noperlettere*3*tp;
    punteggio=noperlettere+differenza;     //viene calcolato il punteggio


    if (parola=="scarabeo" || parola=="scarabei")                                   //si sommano i vari bonus
        punteggio+=100;
    if (lettereusate==6)
        punteggio+=10;
    else if (lettereusate==7)
        punteggio+=30;
    else if (lettereusate==8)
        punteggio+=50;
    if (!usoj)
        punteggio+=10;




    return punteggio;
}

bool controllodizionario (string parola)
{

    size_t start = 0;                                           //si utilizza la ricerca dicotomica per verificare
    size_t end = paroledizionario.size()-1;                     //l'esistenza nel dizionario di una parola
    size_t centro = 0;
    if (parola.size()>=3){
        while (start <= end)
        {
            centro = (start + end) / 2;
            if (parola==paroledizionario[start] || parola==paroledizionario[end] || parola==paroledizionario[centro])
                return true;
            if (centro==0 || centro==paroledizionario.size()-1)
                return false;
            if (parola < paroledizionario[centro])
            {
                end = centro - 1;
            }
            else
            {
                start = centro + 1;
            }
        }
    }
    if (parola.size()<=2)                                   //se la parola ha una lunghezza inferiore a tre
    {                                                       //si effettua una ricerca lineare nel vector di string
        for (size_t e=0; e<paroledadue.size();++e)          //contenente le parole da due o una lettera
        {
            if (parola==paroledadue[e])
                return true;
        }
    }
    return false;
}

void stabiliscivincitore(int numerogiocatori)
{
    int posizione=0;                                    //stampa i nomi e il punteggio dei giocatori
    int max=punteggiogiocatori[0];                      //tenendo aggiornato il massimo, la posizione del giocatore con
    int j=0;                                            //punteggio più alto, e una variabile che conta quanti giocatori hanno lo stesso
    selector(47);                                       //punteggio massimo
    cout << nomegiocatori[0] << " : " << punteggiogiocatori[0] << endl;
    for (int i=1;i<numerogiocatori;++i)
    {
        if (punteggiogiocatori[i]>max)
        {
            max=punteggiogiocatori[i];
            posizione=i;
            j=0;
        }
        else   if (punteggiogiocatori[i]==punteggiogiocatori[posizione] && i!=posizione)
        {
            ++j;
        }

        cout << nomegiocatori[i] << " : " << punteggiogiocatori[i] << endl;
    }
    if (j==0)
        cout << "il vincitore e' " << nomegiocatori[posizione] << " con " << punteggiogiocatori[posizione] << " punti " << endl;
    else
    {                                                           //viene stampato il nome del vincitore (se j=0) o dei vincitori
        cout << "i vincitori sono : " << endl;                  //a parimerito se ci sono più giocatori con il punteggio massimo (j>0)
        cout << nomegiocatori[posizione] << endl;
        for (int i=0;i<numerogiocatori;++i)
        {
            if (punteggiogiocatori[i]==punteggiogiocatori[posizione] && i!=posizione)
            {
                cout << nomegiocatori[i] << endl;
            }

        }
        cout << "con il punteggio di " << punteggiogiocatori[posizione] << endl;
    }
    selector(7);
}

bool finegioco(int numerogiocatori,int turno,int lettererimanenti)
{
    string rimanenti;
    int punteggio=0;
    int posizione=0;
    rimanenti=letteregiocatori[turno%numerogiocatori];
    if (rimanenti.size()==0 && lettererimanenti==0)                 //controlla se sia le ttere del sacchetto sia quelle del
    {                                                               //giocatore che ha inserito l'ultima parola siano finite
        for (int i=0;i<numerogiocatori;++i)                         //in caso affermmativo, si aprono due for, uno che scorre i giocatori
        {                                                           //e uno le lettere rimaste a ogni singolo giocatore

            string rimanenti2=letteregiocatori[i];
            for (size_t c=0;c<rimanenti2.size();++c)
            {
                if (rimanenti2[c]>='a' && rimanenti2[c]<='z'){      //controlla che sia una lettera e non il jolly
                    posizione=rimanenti2[c]-'a';                        //e aggiunge il valore di quella lettera al giocatore che ha
                    punteggio+=valorelettere[posizione];                //fatto terminare il gioco
                }
            }
        }
        punteggiogiocatori[turno%numerogiocatori]+=punteggio;       //ritorna inoltre se il gioco è terminato oppure no
        return true;
    }
    return false;

}

void parolamigliore(int turno, int numerogiocatori,vector <string>& parolefattibili)
{




    string confronto;      //serve per confrontare le lettere della parola e quelle sul campo

    string parola;        //parola in esame

    string lettere=letteregiocatori[turno%numerogiocatori];
    string lettere2;
    string intera=lettere;                  //variabili per la gestione delle
    string intera2=lettere;                 //lettre del giocatore

    string formata="";                  //se si dovessero formare altre parole a causa dell'inserimento
    int partenza=0;                     //salva la parola e da dove parte

    string intera3;           //tenere la parola inserita per intero, anche con le lettere inersecate

    bool orizzontale=true;      //direzione di inserimento

    int jolly=0;        //numero jolly del giocatore

    bool controllo=true;        //variabili di controllo
    int usate=0;

    bool usoj=false;                    //variabili per la gestione del
    int punteggiomax=0;                 //punteggio massimo
    int rigamax;
    int colonnamax;
    string parolamax;
    string direzionemax;
    int confrontopunteggio=0;
    int lettereusate=lettere.size();


    selector(79);
    cout << "sto calcolando . . . " << endl;        //informare l'utente
    selector(7);

    if (turno==0)           //per il primo turno
    {
        for (long long int i=0;i<paroledizionario.size();++i)   //per ogni parola del dizionario
        {
            parola=paroledizionario[i];

            intera3=parola;


            for (int x=1; x<9; ++x)         //per ogni riga da cui si può inserire una parola
            {
                parola=intera3;             //ripristina i controlli, la parola e le lettere
                int y=8;
                orizzontale=false;
                jolly=0;

                usoj=false;


                lettere=intera2;
                controllo = true;

                intera=parola;


                if (x+parola.size()<=8) //controlla se arriva nel centro
                {
                    controllo=false;
                    continue;

                }



                for (size_t p=0;p<lettere.size();++p)     //conta il numero di jolly del giocatore
                {
                    if (lettere[p]=='$')
                        ++jolly;
                }


                for (size_t k =0;k<parola.size();++k)   //per ogni lettera della parola
                {
                    if (lettere.size()==0) //se sono finite le lettere del giocatore
                    {                       //ma non quelle della parola
                        controllo=false;    //da errore

                        break;
                    }
                    for (size_t j =0;j<lettere.size();++j)      //per ogni lettera del giocatore
                    {
                        if (parola[k]==lettere[j])    //se il giocatore ha la lettera...
                        {
                            for (size_t w=0;w<lettere.size();++w)
                            {

                                if (w!=j)       //...viene tolta dalle proprie lettere
                                {
                                    lettere2=lettere2+lettere[w];

                                }


                            }

                            lettere=lettere2;       //si modificano le lettere

                            lettere2="";
                            break;
                        }

                        else if (j==lettere.size()-1)      //se il giocatore non ha la lettera
                        {
                            if (jolly>0)                //controlla se ha un jolly
                            {
                                --jolly;
                                usoj=true;
                                parola[k]='$';      //modifica la parola e le lettere del giocatore
                                for (size_t l=0;l<lettere.size();++l)
                                {
                                    if (lettere[l]!='$')
                                    {
                                        lettere2=lettere2+lettere[l];


                                    }

                                }

                                lettere=lettere2;


                                lettere2="";


                            }
                            else            //se non ha neanche l jolly da errore
                            {
                                controllo = false;

                            }
                        }

                    }

                }

                if (controllo==false)
                    continue;





                lettereusate=lettereusate-lettere.size();  //conta quante lettere ha usato

                if (intera.size()>=3)       //calcola il punteggio, lo confronta col massiomo e aggiorna il massimo
                {
                    confrontopunteggio=calcolapunteggio (intera,x,y,orizzontale,lettereusate,usoj);
                    if (confrontopunteggio>punteggiomax)
                    {
                        punteggiomax=confrontopunteggio;
                        rigamax=x;
                        colonnamax=y;
                        direzionemax="verticale (o in orizzontale con coordinate invertite)";
                        parolamax=intera;
                    }
                }



            }

        }

    }



    else            //turno generale
    {






        orizzontale=false;          //per verticale
        for (int rp=0; rp<15; ++rp)     //per ogni riga
        {
            for (int cp=0; cp<17; ++cp)     //e ogni colonna di libereverticali
            {


                if (libereverticali[rp][cp]==9)     //se uguale a 9 passa alla cella dopo
                    continue;

                for (size_t i=0; i<parolefattibili.size();++i)      //per ogni parola fattibile
                {
                    intera=parolefattibili[i];


                    if ((int)intera.size()<=libereverticali[rp][cp])    //se non interseca nessuna lettera continua
                        continue;


                    if (rp+intera.size()>17)        //se esce dal bordo
                    {
                        continue;
                    }


                    parola="";
                    controllo=true;
                    usate=0;


                    for (size_t w=0;w<intera.size();++w)        //per ogni lettera della parola, la confronta con quella sul campo,
                    {                                       //modifica la parola e conta quante lettere usa il giocatore

                        confronto=intera[w];
                        if (campo[rp+w][cp]!="vuota")
                        {

                            if (confronto!=campo[rp+w][cp])
                            {

                                controllo=false;
                                break;
                            }
                            else
                                parola=parola+'#';
                        }

                        else if (campo[rp+w][cp]=="vuota")
                        {
                            parola=parola+intera[w];
                            ++usate;
                        }


                    }
                    if (usate==0)       //se non usa nessuna delle sue lettere
                    {
                        continue;

                    }
                    if (!controllo)        //se l'inserimento non combacia col campo
                        continue;


                    jolly=0;
                    lettere=intera2;
                    for (size_t p=0;p<lettere.size();++p)   //conta i jolly
                    {
                        if (lettere[p]=='$')
                            ++jolly;
                    }

                    usoj=false;


                    for (size_t k =0;k<parola.size();++k)       //per ogni lettera della parola
                    {

                        if (parola[k]!='#')     //se non è una lettera del campo
                        {
                            if (lettere.size()==0) //se non ha lettere per finire la parola
                            {
                                controllo=false;

                                break;
                            }
                            for (size_t j =0;j<lettere.size();++j)  //per ogni lettera del giocatore
                            {
                                if (parola[k]==lettere[j])      //se coincidono, modifica le lettre
                                {
                                    for (size_t w=0;w<lettere.size();++w)
                                    {

                                        if (w!=j)
                                        {
                                            lettere2=lettere2+lettere[w];

                                        }


                                    }

                                    lettere=lettere2;
                                    lettere2="";
                                    break;
                                }
                                else if (j==lettere.size()-1)   //se non ha la lettera, guarda se ha il jolly
                                {
                                    if (jolly>0)
                                    {
                                        --jolly;
                                        usoj=true;
                                        parola[k]='$';

                                        for (size_t l=0;l<lettere.size();++l)
                                        {
                                            if (lettere[l]!='$')
                                            {
                                                lettere2=lettere2+lettere[l];


                                            }
                                            else
                                            {
                                                for (size_t m=l+1;m<lettere.size();++m)
                                                {
                                                    lettere2=lettere2+lettere[m];
                                                }
                                                break;
                                            }

                                        }

                                        lettere=lettere2;
                                        lettere2="";

                                    }
                                    else    //se non ha ne la lettera ne il jolly da errore
                                    {
                                        controllo = false;
                                        break;
                                    }
                                }

                            }
                        }
                        if (!controllo)
                            break;
                    }
                    if (!controllo)
                        continue;



                    confrontopunteggio=0;




                    if ((rp>0 && campo[rp-1][cp]!="vuota") || (rp+intera.size()<=16 && campo[rp+intera.size()][cp]!="vuota"))
                        continue;       //guarda se ci sono lettere prima o dopo l'inserimento

                    else    //controlla se si formano ulteriori parole e se queste sono valide
                    {
                        for (size_t u=0;u<intera.size();++u)        //per ogni lettera, controlla se a destra e/o
                        {                                           //a sinistra ci sono almeno altre due lettere
                            if (rp+(int)u>=0 && rp+(int)u<17)
                            {
                                if (campo[rp+u][cp]=="vuota")
                                {
                                    if ((cp>1 && campo[rp+u][cp-1]!="vuota" && campo[rp+u][cp-2]!="vuota") ||
                                            (cp>0 && cp<16 && campo[rp+u][cp-1]!="vuota" && campo[rp+u][cp+1]!="vuota") ||
                                            (cp<15 && campo[rp+u][cp+1]!="vuota" && campo[rp+u][cp+2]!="vuota"))
                                    {
                                        int k=1;                //se vero, calcola la parola formata, da dove parte,
                                        partenza=cp;            //e ne controlla la validità, e la somma al punteggio
                                        while (cp-k>=0 && cp-k<=16 && campo[rp+u][cp-k]!="vuota")
                                        {
                                            --partenza;
                                            ++k;
                                        }
                                        k=0;
                                        while (partenza+k<17 && (partenza+k==cp || campo[rp+u][partenza+k]!="vuota"))
                                        {
                                            if (partenza+k==cp)
                                            {
                                                formata=formata+intera[u];
                                            }
                                            else
                                            {
                                                formata=formata+campo[rp+u][partenza+k];
                                            }
                                            ++k;
                                        }
                                        if (!controllodizionario(formata))
                                        {
                                            controllo=false;
                                            break;
                                        }
                                        else
                                            confrontopunteggio+=calcolapunteggio(formata,rp+u,partenza,orizzontale,1,true);
                                        formata="";
                                    }
                                }

                            }

                        }
                    }


                    if (!controllo)
                        continue;














                    //conta le lettere usate
                    if (intera.size()>=3)       //calcola il punteggio, lo confronta col massiomo, e aggiorna il massimo
                    {
                        confrontopunteggio+=calcolapunteggio (intera,rp,cp,orizzontale,usate,usoj);
                        if (confrontopunteggio>punteggiomax)
                        {
                            punteggiomax=confrontopunteggio;
                            rigamax=rp;
                            colonnamax=cp;
                            direzionemax="verticale";
                            parolamax=intera;
                        }
                    }




                }
            }

        }
        orizzontale=true;   //per l'inserimento orizzontale

        for (int cp=0; cp<15; ++cp)     //per ogni colonna
        {
            for (int rp=0; rp<17; ++rp) //e ogni riga di libereorizzontali
            {
                if (libereorizzontali[rp][cp]==9)   //se uguale a 9 continua con la cella dopo
                    continue;

                for (size_t i=0; i<parolefattibili.size();++i)  //per ogni parola fattibile
                {
                    intera=parolefattibili[i];







                    if ((int)intera.size()<=libereorizzontali[rp][cp])  //controlla se interseca
                        continue;





                    if (cp+intera.size()>17) //controlla che non esca dai bordi
                    {
                        continue;
                    }





                    usate=0;
                    controllo=true;
                    parola="";




                    for (size_t w=0;w<intera.size();++w)    //per ogni lettera della parola, controlla che combaci col campo,
                    {                                       //modifica la parola e conta le lettere usate
                        confronto=intera[w];
                        if (campo[rp][cp+w]!="vuota")
                        {

                            if (confronto!=campo[rp][cp+w])
                            {
                                controllo=false;
                                break;
                            }
                            else
                                parola=parola+'#';
                        }

                        else if (campo[rp][cp+w]=="vuota")
                        {
                            parola=parola+intera[w];
                            ++usate;
                        }



                    }
                    if (usate==0)
                    {
                        continue;

                    }
                    if (!controllo)
                        continue;



                    jolly=0;
                    lettere=intera2;

                    for (size_t p=0;p<lettere.size();++p)   //conta i jolly
                    {
                        if (lettere[p]=='$')
                            ++jolly;
                    }

                    usoj=false;




                    for (size_t k =0;k<parola.size();++k)   //per ogni lettera della parola
                    {
                        if (parola[k]!='#')     //non già sul campo
                        {
                            if (lettere.size()==0)  //controlla se ha ancora lettere per fare la parola
                            {
                                controllo=false;

                                break;
                            }
                            for (size_t j =0;j<lettere.size();++j)      //per ogni lettera del giocatore
                            {
                                if (parola[k]==lettere[j])          //controlla se ha la lettera, e nel caso la toglie da quelle del giocatore
                                {
                                    for (size_t w=0;w<lettere.size();++w)
                                    {

                                        if (w!=j)
                                        {
                                            lettere2=lettere2+lettere[w];

                                        }


                                    }

                                    lettere=lettere2;
                                    lettere2="";
                                    break;
                                }
                                else if (j==lettere.size()-1)       //se non ha la lettera, guarda se ha il jolly
                                {
                                    if (jolly>0)
                                    {
                                        --jolly;
                                        usoj=true;
                                        parola[k]='$';

                                        for (size_t l=0;l<lettere.size();++l)
                                        {
                                            if (lettere[l]!='$')
                                            {
                                                lettere2=lettere2+lettere[l];

                                            }
                                            else
                                            {
                                                for (size_t m=l+1;m<lettere.size();++m)
                                                {
                                                    lettere2=lettere2+lettere[m];
                                                }
                                                break;
                                            }

                                        }

                                        lettere=lettere2;
                                        lettere2="";

                                    }
                                    else        //se non ha neanche il jolly, da errore
                                    {
                                        controllo = false;
                                        break;
                                    }
                                }

                            }
                        }
                        if (!controllo)
                        {
                            break;
                        }
                    }
                    if (!controllo)
                        continue;




                    confrontopunteggio=0;





                    if ((cp>0 && campo[rp][cp-1]!="vuota") || (cp+intera.size()<=16 && campo[rp][cp+intera.size()]!="vuota"))
                        continue;       //controlla se ci sono lettre a destra o a sinistra della parola

                    else                //controlla se si formano altre parole a causa dell'inserimento
                    {
                        for (size_t u=0;u<intera.size();++u) //per ogni lettera, controlla se sopra e/o
                        {                                    //sotto ci sono almeno altre due lettere
                            if (cp+(int)u>=0 && cp+(int)u<17)
                            {
                                if (campo[rp][cp+u]=="vuota")
                                {
                                    if ((rp>1 && campo[rp-1][cp+u]!="vuota" && campo[rp-2][cp+u]!="vuota") ||
                                            (rp>0 && rp<16 && campo[rp-1][cp+u]!="vuota" && campo[rp+1][cp+u]!="vuota") ||
                                            (rp<15 && campo[rp+1][cp+u]!="vuota" && campo[rp+2][cp+u]!="vuota"))
                                    {
                                        int k=1;               //se vero, calcola la parola formata, da dove parte,
                                        partenza=rp;           //e ne controlla la validità, e la somma al punteggio
                                        while (rp-k>=0 && rp-k<=16 && campo[rp-k][cp+u]!="vuota")
                                        {
                                            --partenza;
                                            ++k;
                                        }
                                        k=0;
                                        while (partenza+k<17 && (partenza+k==rp || campo[partenza+k][cp+u]!="vuota"))
                                        {
                                            if (partenza+k==rp)
                                            {
                                                formata=formata+intera[u];
                                            }
                                            else
                                            {

                                                formata=formata+campo[partenza+k][cp+u];
                                            }
                                            ++k;
                                        }
                                        if (!controllodizionario(formata))
                                        {
                                            controllo=false;
                                            break;
                                        }
                                        else
                                            confrontopunteggio+=calcolapunteggio(formata,partenza,cp+u,orizzontale,1,true); //aggiorna il punteggio
                                        formata="";
                                    }
                                }
                            }}
                    }

                    if (!controllo)
                        continue;

                    //conta le lettere usate
                    if (intera.size()>=3)       //calcola il punteggio, lo confronta con il massimo e aggiorna il massimo
                    {
                        confrontopunteggio+=calcolapunteggio (intera,rp,cp,orizzontale,usate,usoj);
                        if (confrontopunteggio>punteggiomax)
                        {
                            punteggiomax=confrontopunteggio;
                            rigamax=rp;
                            colonnamax=cp;
                            direzionemax="orizzontale";
                            parolamax=intera;
                        }
                    }




                }
            }


        }







    }
    system("CLS");      //pulisce lo schermo, per togliere il sto calcolando

    if (turno!=0)
        stampapunteggio(numerogiocatori);       //ristampa i punteggi

    //STAMPA DEL CAMPO
    stampaCampo();
    selector(79);               //ristampa le lettere
    cout << nomegiocatori[turno%numerogiocatori] << " le tue lettere sono : " << letteregiocatori[turno%numerogiocatori] << endl;
    selector(7);

    if (punteggiomax!=0){   //stampa il suggerimento con coordinate e direzione se il massimo è diverso da zero
        selector(79);
        cout <<"suggerimento: "<<parolamax<<", partenza:("<<rigamax<<","<<colonnamax<<"), in "<<direzionemax<<endl;
        selector(7);
    }
    else{               //non si possono inserire parole di lunghezza supeiore a tre quindi non c'è un massimo
        selector(79);
        cout << "non puoi inserire nessuna parola da 3 o piu' lettere, prova con una da due" << endl;
        selector(7);
    }
}

void sfoltiscidizionario(vector <string>& parolefattibili,int turno){
    for (size_t i=0;i<paroledizionario.size();++i){         //per ogni parola del dizionario
        bool presente=false;
        string parola=paroledizionario[i];
        string lettere=letteregiocatori[turno];
        for (size_t j=0;j<parola.size();++j){           //per ogni lettera di una parola del dizionario
            for (size_t k=0;k<lettere.size();++k){      //per ogni lettera del giocatore corrente
                if (parola[j]==lettere[k]){
                    presente=true;                          //controlla che il giocatore abbia almeno una
                    parolefattibili.push_back(parola);      //delle lettere che compongono la parola
                    break;                                  //e in caso affermativo riempe il vector di string parolefattibili
                }
            }
            if (presente)
                break;
        }
    }

}

void stampapunteggio(int numerogiocatori){
    selector(79);
    cout << "Punteggio :" << endl;
    for (int i=0;i<numerogiocatori;++i){                            //stampa i punteggi di tutti i giocatori
        cout << nomegiocatori[i] << " : " << punteggiogiocatori[i];     //al turno attuale
        if (i==ultimoainserire){
            cout << " ( +" << punteggioturno << " punti )";         //stampa anche il punteggio totalizzato dall'ultimo
        }                                                           //giocatore che ha inserito una parola
        cout << endl;
    }
    selector(7);
}

void riempidizionario(){
    string voce;
    ifstream dizionario;
    dizionario.open ("F:\\scarabeofinito\\italiano.txt");   //apre il dizionario tramite percorso assoluto

    for (long long int i=0;i<60428;++i){            //per ogni parola del dizionario, si salva la voce
        //e in base alla lunghezza viene inserita nel vector di string
        dizionario >> voce;                         //paroledadue (<3) o in paroledizionario (>=3)
        if (voce.size()<=2)
            paroledadue.push_back(voce);

        if(voce.size()>=3)
            paroledizionario.push_back(voce);
    }
    dizionario.close();                             //chiude il dizionario
}

void sistemamatrici()
{
    for (int r=0; r<17; ++r){               //per ogni riga di libereorizzontali
        for (int c=0; c<15; ++c){           //per ogni colonna di libereorizzontali
            int conta=0;
            for (int u=c; u<17;++u){        //per ogni colonna del campo a partire dalla colonna in esame di libereorizzontali
                if (campo[r][u]=="vuota")
                {
                    ++conta;                //se la cella del campo è vuota incrementa conta
                    if (conta==9)           //se si arriva a 9 si ferma dato che si possono inserire un massimo di 8 lettere
                    {
                        libereorizzontali[r][c]=conta;
                        break;
                    }
                }
                else                        //altrimenti si inserisce in libereorizzontali
                {                           //quante celle libere ha alla sua destra
                    libereorizzontali[r][c]=conta;
                    break;
                }
                if (u==16)                          //se è l'ultima colonna, si inserisce 9
                {                                   //perchè non interseca nessuna lettera
                    libereorizzontali[r][c]=9;
                }
            }
        }
    }
    for (int c=0; c<17; ++c){               //per ogni colonna di libereverticali
        for (int r=0; r<15; ++r){           //per ogni riga di libereverticali
            int conta=0;
            for (int u=r; u<17;++u){        //per ogni riga del campo a partire dalla riga in esame di libereverticali
                if (campo[u][c]=="vuota")
                {                           //se la cella del campo è vuota incrementa conta
                    ++conta;
                    if (conta==9)       //se si arriva a 9 si ferma dato che si possono inserire un massimo di 8 lettere
                    {
                        libereverticali[r][c]=conta;
                        break;
                    }
                }
                else            //altrimenti si inserisce in libere
                {               //quante celle libere ha sotto in verticale
                    libereverticali[r][c]=conta;
                    break;
                }
                if (u==16)              //se è l'ultima riga, si inserisce 9
                {                       //perchè non interseca nessuna lettera
                    libereverticali[r][c]=9;
                }
            }
        }
    }


}

//FUNZIONE PER GESTIRE I COLORI DELLA STAMPACAMPO ()
void selector(unsigned short color)
{
    HANDLE hCon = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hCon,color);
}
