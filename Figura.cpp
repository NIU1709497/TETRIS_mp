#ifndef JOC_H
#define JOC_H

#include "Figura.h"
//#include "Tauler.h"
#include <string>
using namespace std;

#include <fstream>
#include <iostream>

Figura::Figura()
{
    for (int i = 0; i < MAX_AMPLADA; i++)
    {
        for (int j = 0; j < MAX_ALCADA; j++)
        {
            m_formaFiguraActual[i][j] = COLOR_NEGRE;
        }
    }

    m_color = COLOR_NEGRE;
    m_posicioX = -1;
    m_posicioY = -1;
    m_tipus = NO_FIGURA;
}


Figura::Figura(TipusFigura tipus, int estat)
{
    string arxiu;

    m_tipus = tipus;

    for (int fila = 0; fila < MAX_ALCADA; fila++)
    {
        for (int columna = 0; columna < MAX_AMPLADA; columna++)
        {
            m_formaFiguraActual[fila][columna] = COLOR_NEGRE;
        }
    }

    switch (m_tipus)
    {
    case FIGURA_J:
        m_formaFiguraActual[0][0] = COLOR_BLAUFOSC;
        m_formaFiguraActual[1][0] = COLOR_BLAUFOSC;
        m_formaFiguraActual[1][1] = COLOR_BLAUFOSC;
        m_formaFiguraActual[1][2] = COLOR_BLAUFOSC;

        m_color = COLOR_BLAUFOSC;
        break;

    case FIGURA_L:
        m_formaFiguraActual[0][2] = COLOR_TARONJA;
        m_formaFiguraActual[1][0] = COLOR_TARONJA;
        m_formaFiguraActual[1][1] = COLOR_TARONJA;
        m_formaFiguraActual[1][2] = COLOR_TARONJA;

        m_color = COLOR_TARONJA;
        break;

    case FIGURA_T:
        m_formaFiguraActual[0][1] = COLOR_MAGENTA;
        m_formaFiguraActual[1][0] = COLOR_MAGENTA;
        m_formaFiguraActual[1][1] = COLOR_MAGENTA;
        m_formaFiguraActual[1][2] = COLOR_MAGENTA;

        m_color = COLOR_MAGENTA;
        break;

    case FIGURA_S:
        m_formaFiguraActual[0][1] = COLOR_VERD;
        m_formaFiguraActual[0][2] = COLOR_VERD;
        m_formaFiguraActual[1][0] = COLOR_VERD;
        m_formaFiguraActual[1][1] = COLOR_VERD;

        m_color = COLOR_VERD;
        break;

    case FIGURA_Z:
        m_formaFiguraActual[0][0] = COLOR_VERMELL;
        m_formaFiguraActual[0][1] = COLOR_VERMELL;
        m_formaFiguraActual[1][1] = COLOR_VERMELL;
        m_formaFiguraActual[1][2] = COLOR_VERMELL;

        m_color = COLOR_VERMELL;
        break;

    case FIGURA_I:
        m_formaFiguraActual[1][0] = COLOR_BLAUCEL;
        m_formaFiguraActual[1][1] = COLOR_BLAUCEL;
        m_formaFiguraActual[1][2] = COLOR_BLAUCEL;
        m_formaFiguraActual[1][3] = COLOR_BLAUCEL;

        m_color = COLOR_BLAUCEL;
        break;

    case FIGURA_O:
        m_formaFiguraActual[0][0] = COLOR_GROC;
        m_formaFiguraActual[0][1] = COLOR_GROC;
        m_formaFiguraActual[1][0] = COLOR_GROC;
        m_formaFiguraActual[1][1] = COLOR_GROC;

        m_color = COLOR_GROC;
        break;
    default:
        break;
    }


    /*switch (m_tipus)
    {
    case FIGURA_J:
        arxiu = "FIGURA_J_1.txt";
        m_color = COLOR_BLAUFOSC;
        break;
    case FIGURA_L:
        arxiu = "FIGURA_L_1.txt";
        m_color = COLOR_TARONJA;
        break;
    case FIGURA_T:
        arxiu = "FIGURA_T_1.txt";
        m_color = COLOR_MAGENTA;
        break;
    case FIGURA_S:
        arxiu = "FIGURA_S_1.txt";
        m_color = COLOR_VERD;
        break;
    case FIGURA_Z:
        arxiu = "FIGURA_Z_1.txt";
        m_color = COLOR_VERMELL;
        break;
    case FIGURA_I:
        arxiu = "FIGURA_I_1.txt";
        m_color = COLOR_BLAUCEL;
        break;
    case FIGURA_O:
        arxiu = "FIGURA_O_1.txt";
        m_color = COLOR_GROC;
        break;
    default:
        estatActualitzat = false;
        break;
    }

    posicionsFigures(arxiu);
    */

    //COLOCA LA FIGURA A L'ESTAT DESITJAT
    if (estat == 3)
    {
        //m_estat = 0;

        //antihorari
        //estatActualitzat = girarFigura(GIR_ANTI_HORARI); 
        girarFigura(GIR_ANTI_HORARI);
    }

    else
    {
        //m_estat = 0;

        for (int i = 0; i < estat; i++)
        {
            //horari
            //estatActualitzat = girarFigura(GIR_HORARI);
            girarFigura(GIR_HORARI);
        }
    }


    /*switch (m_tipus)
    {
    case FIGURA_J:
        prefix = "FIGURA_J_";
        m_color = COLOR_BLAUFOSC;
        break;
    case FIGURA_L:
        prefix = "FIGURA_L_";
        m_color = COLOR_TARONJA;
        break;
    case FIGURA_T:
        prefix = "FIGURA_T_";
        m_color = COLOR_MAGENTA;
        break;
    case FIGURA_S:
        prefix = "FIGURA_S_";
        m_color = COLOR_VERD;
        break;
    case FIGURA_Z:
        prefix = "FIGURA_Z_";
        m_color = COLOR_VERMELL;
        break;
    case FIGURA_I:
        prefix = "FIGURA_I_";
        m_color = COLOR_BLAUCEL;
        break;
    case FIGURA_O:
        prefix = "FIGURA_O_";
        m_color = COLOR_GROC;
        break;
    default:
        canviFet = false;
        break;
    }

    switch (m_estat)
    {
    case 0:
        sufix = "1.txt";
        break;
    case 1:
        sufix = "2.txt";
        break;
    case 2:
        sufix = "3.txt";
        break;
    case 3:
        sufix = "4.txt";
        break;
    default:
        canviFet = false;
        break;
    }

    arxiu = prefix + sufix;

    posicionsFigures(arxiu);*/
}

void Figura::posicionsFigures(const string& nomArxiu)
{
    ifstream arxiu;
    arxiu.open(nomArxiu);

    if (arxiu.is_open())
    {
        for (int i = 0; i < MAX_AMPLADA; i++)
        {
            for (int j = 0; j < MAX_ALCADA; j++)
            {
                arxiu >> m_formaFiguraActual[i][j];
            }
        }
    }

    arxiu.close();
}


void Figura::girarFigura(DireccioGir sentit)
{
    //bool canviFet = false;
    int nFilesFigura, nColumnesFigura;

    if (m_tipus != FIGURA_O) //LA FIGURA_O (EL QUADRAT) QUAN GIRA ES QUEDA IGUAL
    {
        //canviFet = true;

        //ASSIGNA EL NOMBRE DE FILES I COLUMNES DE LA MATRIU QUE OCUPA LA FIGURA AL GIRAR
        if (m_tipus == FIGURA_I)
        {
            nFilesFigura = MAX_ALCADA;
            nColumnesFigura = MAX_AMPLADA;
        }

        else
        {
            nFilesFigura = 3;
            nColumnesFigura = 3;
        }

        //GIRAR LA MATTRTIU EN FUNCIO DEL SENTIT DEL GIR
        if (sentit == GIR_HORARI)
        {
            //GIRA LA MATRIU 90 GRAUS EN SENTIT HORARI
            for (int fila = 0; fila < nFilesFigura / 2; fila++)
            {
                for (int columna = fila; columna < nColumnesFigura - 1 - fila; columna++)
                {
                    int numTemporal = m_formaFiguraActual[fila][columna];

                    m_formaFiguraActual[fila][columna] = m_formaFiguraActual[nFilesFigura - 1 - columna][fila];

                    m_formaFiguraActual[nFilesFigura - 1 - columna][fila] = m_formaFiguraActual[nFilesFigura - 1 - fila][nColumnesFigura - 1 - columna];
                    m_formaFiguraActual[nFilesFigura - 1 - fila][nColumnesFigura - 1 - columna] = m_formaFiguraActual[columna][nColumnesFigura - 1 - fila];
                    m_formaFiguraActual[columna][nColumnesFigura - 1 - fila] = numTemporal;
                }
            }
        }

        else //GIR_ANTI_HORARI
        {
            //GIRA LA MATRIU 90 GRAUS EN SENTIT ANTIHORARI
            for (int fila = 0; fila < nFilesFigura / 2; fila++)
            {
                for (int columna = fila; columna < nColumnesFigura - 1 - fila; columna++)
                {
                    int numTemporal = m_formaFiguraActual[fila][columna];

                    m_formaFiguraActual[fila][columna] = m_formaFiguraActual[columna][nColumnesFigura - 1 - fila];

                    m_formaFiguraActual[columna][nColumnesFigura - 1 - fila] = m_formaFiguraActual[nFilesFigura - 1 - fila][nColumnesFigura - 1 - columna];
                    m_formaFiguraActual[nFilesFigura - 1 - fila][nColumnesFigura - 1 - columna] = m_formaFiguraActual[nColumnesFigura - 1 - columna][fila];
                    m_formaFiguraActual[nFilesFigura - 1 - columna][fila] = numTemporal;
                }
            }
        }
    }

    //ACTUALITZAR ESTAT DE LA FIGURA
    /*switch (m_estat)
    {
    case 0:
        m_estat = (sentit == GIR_HORARI) ? ++m_estat : 3;
        break;
    case 3:
        m_estat = (sentit == GIR_HORARI) ? 0 : --m_estat;
        break;
    default:
        m_estat = (sentit == GIR_HORARI) ? ++m_estat : --m_estat;
        break;
    }*/

    //canviFet = true;


    /*string arxiu = "", prefix, sufix;
    bool canviFet = true;

    switch (m_tipus)
    {
    case FIGURA_J:
        prefix = "FIGURA_J_";
        break;
    case FIGURA_L:
        prefix = "FIGURA_L_";
        break;
    case FIGURA_T:
        prefix = "FIGURA_T_";
        break;
    case FIGURA_S:
        prefix = "FIGURA_S_";
        break;
    case FIGURA_Z:
        prefix = "FIGURA_Z_";
        break;
    case FIGURA_I:
        prefix = "FIGURA_I_";
        break;
    case FIGURA_O:
        prefix = "FIGURA_O_";
        break;
    default:
        canviFet = false;
        break;
    }

    switch (m_estat)
    {
    case 0:
        sufix = (sentit == GIR_HORARI) ? "2.txt" : "4.txt";
        m_estat = (sentit == GIR_HORARI) ? 1 : 3;
        break;
    case 1:
        sufix = (sentit == GIR_HORARI) ? "3.txt" : "1.txt";
        m_estat = (sentit == GIR_HORARI) ? 2 : 0;
        break;
    case 2:
        sufix = (sentit == GIR_HORARI) ? "4.txt" : "2.txt";
        m_estat = (sentit == GIR_HORARI) ? 3 : 1;
        break;
    case 3:
        sufix = (sentit == GIR_HORARI) ? "1.txt" : "3.txt";
        m_estat = (sentit == GIR_HORARI) ? 0 : 2;
        break;
    default:
        canviFet = false;
        break;
    }

    arxiu = prefix + sufix;

    posicionsFigures(arxiu);

    return canviFet;
    */
}


void Figura::movimentHoritzontal(int direccio)
{
    m_posicioX += direccio;
    //si volem anar a la dreta, direccio=1, m_posicio augmenta en 1
    //si volem anar a la esquerra, direccio = -1, m_posicio disminueix en 1
}

void Figura::cauFigura()
{
    ++m_posicioY;
    //com la figura esta caient, la figura descendeix cap a valors mes grans de Y, per tant augmentem la posicio Y
}


//NECESSARIA PER FER LES COMPROVACIONS DE GIRS
void Figura::imprimeixFigura()
{
    for (int i = 0; i < MAX_AMPLADA; i++)
    {
        cout << "|";

        for (int j = 0; j < MAX_ALCADA; j++)
        {
            cout << m_formaFiguraActual[i][j] << " ";
        }

        cout << "|" << endl;
    }
}

#endif