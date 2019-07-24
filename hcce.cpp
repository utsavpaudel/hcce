#include "hcce.h"
#include "ui_hcce.h"
//#include "admin.h"
#include <QPixmap>
#include <QMessageBox>

HCCE::HCCE(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::HCCE)
{

    ui->setupUi(this);
    ui->stackedWidget->setCurrentIndex(1);
    ui->stackedWidget_3->setCurrentIndex(0);
    ui->stackedWidget_2->setCurrentIndex(0);
    QPixmap pix(":/pic/img/p.jpg");
    QPixmap pix1(":/pic/img/safety-cap-500x500.png");
    int w=ui->label_pic->width();
    int h=ui->label_pic->height();
    ui->label_pic->setPixmap(pix.scaled(w,h,Qt::KeepAspectRatio));
    int w1=ui->label_28->width();
    int h1=ui->label_28->height();
    ui->label_28->setPixmap(pix1.scaled(w1,h1,Qt::KeepAspectRatio));
}

HCCE::~HCCE()
{
    delete ui;
}

//database
QSqlDatabase HCCE:: connect(){
    QSqlDatabase db=QSqlDatabase::addDatabase("QMYSQL");
    db.setHostName("localhost");
    db.setUserName("root");
    db.setPassword("");
    db.setDatabaseName("wall estimation");
    db.open();
    return db;
}

void HCCE:: closeConnection(QSqlDatabase db){
    db.close();
}

void HCCE:: loadPriceandVol(QSqlDatabase db){
    QSqlQuery query(db);
    //material list table data input
    query.exec("SELECT `unitprice`, `volume(m3)` FROM `structure materials`");
    query.next();
    this->b1p=query.value(0).toDouble();
    this->brick_vol=query.value(1).toDouble();
    query.next();
    this->b2p=query.value(0).toDouble();
    query.next();
    //b3p=query.value(2).toDouble();
    query.next();
    this->opc=query.value(0).toDouble();
    this->cem_vol=query.value(1).toDouble();
    query.next();
    this->ppc=query.value(0).toDouble();
    query.next();
    this->snd=query.value(0).toDouble();
    query.next();
    this->grav=query.value(0).toDouble();
    query.next();
    this->rods=query.value(0).toDouble();
    this->rod_dens=query.value(1).toDouble();
    query.next();
    this->stn=query.value(0).toDouble();
    this->stn_dens=query.value(1).toDouble();
    query.next();
    this->bvcs=query.value(1).toDouble();
    //finishing table data input
    query.exec("SELECT `unitprice` FROM `finishing`");
    query.next();
    this->marble=query.value(0).toDouble();
    query.next();
    this->tile=query.value(0).toDouble();
    query.next();
    this->granite=query.value(0).toDouble();
    query.next();
    this->alum=query.value(0).toDouble();
    query.next();
    this->wood=query.value(0).toDouble();
    query.next();
    this->upvc=query.value(0).toDouble();
    //admin table data input
    query.exec("SELECT `user`,`password` FROM `admin`");
    query.next();
    this->username=query.value(0).toString();
    this->password=query.value(1).toString();
}


void HCCE::on_DSA_valueChanged(double arg1)
{
    this->ha=arg1;
}

void HCCE::on_SBNS_valueChanged(int arg1)
{
    this->sn=arg1;
}



void HCCE::on_CBFT_3_currentIndexChanged(int index)
{
    this->bt=index;
}

void HCCE::on_CBFT_currentIndexChanged(int index)
{
    this->ft=index;
}
void HCCE::on_SBNC_2_valueChanged(double arg1)
{
    this->dlo=arg1;
}
void HCCE::on_CBDC_currentIndexChanged(int index)
{
    this->cd=index;
}

void HCCE::on_DSLOD_valueChanged(double arg1)
{
    this->dlo=arg1;
}

void HCCE::on_DSLID_valueChanged(double arg1)
{
    this->dli=arg1;
}

void HCCE::on_DSTS_valueChanged(double arg1)
{
    this->st_1=arg1;
}


void HCCE::on_DSWH_valueChanged(double arg1)
{
    this->wh_1=arg1;
}

void HCCE::on_DSWW_valueChanged(double arg1)
{
    this->wwo_1 = arg1;
}

void HCCE::on_DSWWI_valueChanged(double arg1)
{
    this->wwi_1=arg1;
}

void HCCE::on_DSDB_currentIndexChanged(int index)
{
    this->bd_1=index;
}

void HCCE::on_DSWIS_valueChanged(double arg1)
{
    this->ws_1=arg1;
}
void HCCE::on_DSLIS_valueChanged(double arg1)
{
    this->len=arg1;
}

void HCCE::on_DSNOD_valueChanged(int arg1)
{
    this-> dno_1=arg1;
}

void HCCE::on_DSNOW_valueChanged(int arg1)
{
    this->wno_1=arg1;
}

void HCCE::on_DSODW_valueChanged(double arg1)
{
    this->dwo_1=arg1;
}

void HCCE::on_DSODH_valueChanged(double arg1)
{
    this->dho_1=arg1;
}

void HCCE::on_CBTWI_currentIndexChanged(int index)
{
    this->wto_1=index;
}

void HCCE::on_DSOWNW_valueChanged(double arg1)
{
    this->wnwo_1=arg1;
}

void HCCE::on_DSOWNH_valueChanged(double arg1)
{
    this->who_1=arg1;
}

void HCCE::on_DSNDI_valueChanged(int arg1)
{
    this-> dni_1=arg1;
}

void HCCE::on_DSNWI_valueChanged(int arg1)
{
    this->wni_1=arg1;
}

void HCCE::on_DSIDW_valueChanged(double arg1)
{
    this-> dwi_1=arg1;
}

void HCCE::on_DSIDH_valueChanged(double arg1)
{
    this-> dhi_1=arg1;
}

void HCCE::on_CBTWO_currentIndexChanged(int index)
{
    this->wti_1=index;
}

void HCCE::on_DSIWNW_valueChanged(double arg1)
{
    this->wnwi_1=arg1;
}

void HCCE::on_DSIWNH_valueChanged(double arg1)
{
    this-> whi_1=arg1;
}

void HCCE::on_PBHome_clicked()
{
    this->ui->stackedWidget->setCurrentIndex(0);
}

void HCCE::on_PBStruct_clicked()
{
    this->ui->stackedWidget->setCurrentIndex(1);
}

void HCCE::on_PBWall_clicked()
{
    this-> ui->stackedWidget->setCurrentIndex(2);
}

void HCCE::on_PBFrn_clicked()
{
    this-> ui->stackedWidget->setCurrentIndex(3);
}

void HCCE::on_PBSt_clicked()
{
    ui->stackedWidget_2->setCurrentIndex(0);
    this-> ui->stackedWidget->setCurrentIndex(4);
}
void HCCE::on_DSWH_3_valueChanged(double arg1)
{
    wh_2=arg1;
}

void HCCE::on_DSWW_3_valueChanged(double arg1)
{
    wwo_2=arg1;
}

void HCCE::on_DSWWI_3_valueChanged(double arg1)
{
    wwi_2=arg1;
}

void HCCE::on_DSDB_3_currentIndexChanged(int index)
{
    bd_2=index;
}

void HCCE::on_DSNOD_3_valueChanged(int arg1)
{
    dno_2=arg1;
}

void HCCE::on_DSNOW_3_valueChanged(int arg1)
{
    wno_2=arg1;
}

void HCCE::on_DSODW_3_valueChanged(double arg1)
{
    dwo_2=arg1;
}

void HCCE::on_DSODH_3_valueChanged(double arg1)
{
    dho_2=arg1;
}

void HCCE::on_CBTWI_3_currentIndexChanged(int index)
{
    wti_2=index;
}

void HCCE::on_DSOWNW_3_valueChanged(double arg1)
{
    wnwo_2=arg1;
}

void HCCE::on_DSOWNH_3_valueChanged(double arg1)
{
    who_2=arg1;
}

void HCCE::on_DSNDI_3_valueChanged(int arg1)
{
    dni_2=arg1;
}

void HCCE::on_DSNWI_3_valueChanged(int arg1)
{
    wni_2=arg1;
}

void HCCE::on_DSIDW_3_valueChanged(double arg1)
{
    dwi_2=arg1;
}

void HCCE::on_DSIDH_3_valueChanged(double arg1)
{
    dhi_2=arg1;
}

void HCCE::on_CBTWO_3_activated(int index)
{
    wto_2=index;
}

void HCCE::on_DSIWNW_3_valueChanged(double arg1)
{
    wnwi_2=arg1;
}

void HCCE::on_DSIWNH_3_valueChanged(double arg1)
{
    whi_2=arg1;
}
void HCCE::on_DSWH_2_valueChanged(double arg1)
{
    wh_3=arg1;
}

void HCCE::on_DSWW_2_valueChanged(double arg1)
{
    wwo_3=arg1;
}

void HCCE::on_DSWWI_2_valueChanged(double arg1)
{
    wwi_3=arg1;
}

void HCCE::on_DSDB_2_currentIndexChanged(int index)
{
    bd_3=index;
}


void HCCE::on_DSNOD_2_valueChanged(int arg1)
{
    dno_3=arg1;
}

void HCCE::on_DSNOW_2_valueChanged(int arg1)
{
    wno_3=arg1;
}

void HCCE::on_DSODW_2_valueChanged(double arg1)
{
    dwo_3=arg1;
}

void HCCE::on_DSODH_2_valueChanged(double arg1)
{
    dho_3=arg1;
}

void HCCE::on_CBTWI_2_currentIndexChanged(int index)
{
    wti_3=index;
}

void HCCE::on_DSOWNW_2_valueChanged(double arg1)
{
    wnwo_3=arg1;
}

void HCCE::on_DSOWNH_2_valueChanged(double arg1)
{
    who_3=arg1;
}

void HCCE::on_DSNDI_2_valueChanged(int arg1)
{
    dni_3=arg1;
}

void HCCE::on_DSNWI_2_valueChanged(int arg1)
{
    wni_3=arg1;
}

void HCCE::on_DSIDW_2_valueChanged(double arg1)
{
    dwi_3=arg1;
}

void HCCE::on_DSIDH_2_valueChanged(double arg1)
{
    dhi_3=arg1;
}

void HCCE::on_CBTWO_2_activated(int index)
{
    wto_3=index;
}

void HCCE::on_DSIWNW_2_valueChanged(double arg1)
{
    wnwi_3=arg1;
}

void HCCE::on_DSIWNH_2_valueChanged(double arg1)
{
    whi_3=arg1;
}


void HCCE::on_pushButton_10_clicked()
{
    ui->stackedWidget_3->setCurrentIndex(0);
}

void HCCE::on_pushButton_11_clicked()
{
     ui->stackedWidget_3->setCurrentIndex(1);
}

void HCCE::on_pushButton_19_clicked()
{
    ui->stackedWidget_2->setCurrentIndex(1);
}

void HCCE::on_pushButton_20_clicked()
{
     ui->stackedWidget_2->setCurrentIndex(0);
}

void HCCE::on_PBSt_2_clicked()
{
    this->costdpc=dpc();
    this->costwall=wall();
    this->costst=slab()+beam()+foundation();
    this->coststr=stairs();
    this->costfur=window()+door();
    ui->stackedWidget->setCurrentIndex(5);
}


double HCCE:: foundation(){
    double footlen=0, footbreadth=0, footvol=0, foundvol=0, totalvol=0,costfoundation=0;
    footvol = footlen*footbreadth*0.3048;
    foundvol = footlen*3*0.3048*0.2032;
    totalvol = footvol+foundvol;
    costfoundation = totalvol*7500;
    return costfoundation;
}

double HCCE::dpc(){
    double vdpc =0 ,vrdpc =0 ,vcdpc =0 ,vsndpc =0 ,vagdpc =0 ,costdpc=0;
    double hdpc=0.2;
    double wdpc = 0.164;
    vdpc=hdpc*wdpc*5;//(dlo+dli);
    vrdpc=0.04*vdpc;
    vcdpc=0.137*vdpc;
    vsndpc=0.274*vdpc;
    vagdpc=0.548*vdpc;
    costdpc = (vrdpc*rod_dens*rods)+((vcdpc/cem_vol)*opc)+(vsndpc/sand_vol*snd)+(vagdpc/grav_vol*snd);
    return costdpc;
}

double HCCE:: wall(){
    double vwall_1=0,vwall_2=0,vwall_3=0;
    double nbrick=0,vcs=0,vcem=0,vsnd=0,costwall=0;
    vwall_1=(wwo_1*wh_1*dlo)+(wwi_1*wh_1*dli);
    vwall_2=(wwo_2*wh_2*dlo)+(wwi_2*wh_2*dli);
    vwall_3=(wwo_3*wh_3*dlo)+(wwi_3*wh_3*dli);
    nbrick=(vwall_1/bvcs)+(vwall_2/bvcs)+(vwall_3/bvcs);
    double brick=0;
    if(bt==0)  brick=nbrick*b1p;
    else       brick=nbrick*b2p;
      vcs=nbrick*(bvcs-brick_vol);
      vcem=vcs/7;
      vsnd=(6*vcs)/7;
      costwall=brick+((vcem/cem_vol)*ppc)+((vsnd/sand_vol)*snd);
    return costwall;
}

double HCCE:: stairs(){
    double volslab=0,rod_vol=0,cemvol1=0,sndvol=0,aggvol=0;
      volslab=len*ws_1*0.127;    //length of stair variable to amend
      rod_vol=0.0015*volslab;
      cemvol1=(volslab-rod_vol)/7;
      sndvol = 2*(volslab-rod_vol)/7;
      aggvol= 4*(volslab-rod_vol)/7;

    //bricks for stairs
    double lb =len*(6/4);  //length for bricks
    double vb = lb*ws_1*0.1524; //volume of brick with cs
    double nob = vb/bvcs;
    double csvol= vb - (nob*brick_vol);
    double cem_vol2 = csvol/7;
    double snd_vol = 6*(csvol)/7;

    //final pricing
    double costStairs = ((rod_dens*rod_vol*rods)+((cemvol1/cem_vol)*ppc)+(cem_vol2/cem_vol*opc)+((sndvol+snd_vol)*snd)+(aggvol*grav))*sn;
    return costStairs;
}

double HCCE:: slab(){
    double volslab =ha*0.127;
    double volrod = 0.003*volslab;
    double slabcemvol= (volslab-volrod)/7;
    double sndvol=2*(volslab-volrod)/7;
    double aggvol = 4*(volslab-volrod)/7;

    double slabprice= ((volrod*rod_dens*rods)+(slabcemvol/cem_vol)*ppc + (sndvol*snd) + (aggvol*grav))*sn;
    return slabprice;
}

double HCCE:: beam(){

    double area;

    if (bd_1==0){
        area= 0.0697;
    }
    else{
        area=0.0929;
    }

    double lob= dli+dlo;
    double volbeam = lob*area;
    double volrebar = 0.025*volbeam;
    double beamvolcem= (volbeam-volrebar)/7;
    double volsnd= 2*(volbeam-volrebar)/7;
    double volagg = 4*(volbeam-volrebar)/7;

    double beamPrice = ((volrebar*rod_dens*rods)+(beamvolcem/cem_vol)*ppc+ (volsnd*snd)+(volagg*grav))*sn;
    return beamPrice;
}


double HCCE:: door(){
    double a1=0;
    //outer door for floor 1
    double volouterdoor1 = (dwo_1*dho_1*(wwo_1 - 0.0254));
    switch(wti_1){
    case 0 : {
        a1= wood*volouterdoor1;break;
    }
    case 1 : {
        a1= alum*volouterdoor1;break;
    }
    case 2 : {
        a1= upvc*volouterdoor1;
    }
    }
    //outer door for floor 2
    double a2=0;
    double volouterdoor2 = (dwo_2*dho_2*(wwo_2- 0.0254));
    switch(wti_2){
    case 0 : {
        a2= wood*volouterdoor2;break;
    }
    case 1 : {
        a2= alum*volouterdoor2;break;
    }
    case 2 : {
        a2= upvc*volouterdoor2;
    }
    }
    //outer door for floor 3
    double a3=0;
    double volouterdoor3=0;
    volouterdoor3 = (dwo_3*dho_3*(wwo_3- 0.0254));
    switch(wti_3){
    case 0 : {
        a3= wood*volouterdoor3;break;
    }
    case 1 : {
        a3= alum*volouterdoor3;break;
    }
    case 2 : {
        a3= upvc*volouterdoor3;
    }
    }


    //inner door
    double b1=0;
    double volinnerdoor1 =0;
    volinnerdoor1 = (dwi_1*dhi_1*(wwi_1- 0.0254));
    switch(wti_1){
    case 0 : {
        b1= wood*volinnerdoor1;break;
    }
    case 1 : {
        b1= alum*volinnerdoor1;break;
    }
    case 2 : {
        b1= upvc*volinnerdoor1;
    }
    }
    //inner door for floor 2
    double b2=0;
    double volinnerdoor2 = 0;
    volinnerdoor2 = (dwi_2*dhi_2*(wwi_2- 0.0254));
    switch(wti_2){
    case 0 : {
        b2= wood*volinnerdoor2;break;
    }
    case 1 : {
        b2= alum*volinnerdoor2;break;
    }
    case 2 : {
        b2= upvc*volinnerdoor2;
    }
    }
    //inner door for floor 3
    double b3=0;
    double volinnerdoor3= (dwi_3*dhi_3*(wwi_3- 0.0254));
    switch(wti_3){
    case 0 : {
        b3= wood*volinnerdoor3;break;
    }
    case 1 : {
        b3= alum*volinnerdoor3;break;
    }
    case 2 : {
        b3= upvc*volinnerdoor3;
    }
    }
    double dcost = a1+a2+a3+b1+b2+b3;
    return dcost;
}

double HCCE::window(){
    double a1=0;
    //outer window for floor 1
    double volouterwindow1 = (wnwo_1*who_1*(wwo_1- 0.0254));
    switch(wti_1){
    case 0 : {
        a1= wood*volouterwindow1;break;
    }
    case 1 : {
        a1= alum*volouterwindow1;break;
    }
    case 2 : {
        a1= upvc*volouterwindow1;
    }
    }
    //outer window for floor 2
    double a2=0;
    double volouterwindow2 = (wnwo_2*who_2*(wwo_2- 0.0254));
    switch(wti_2){
    case 0 : {
        a2= wood*volouterwindow2;break;
    }
    case 1 : {
        a2= alum*volouterwindow2;break;
    }
    case 2 : {
        a2= upvc*volouterwindow2;
    }
    }
    //outer window for floor 3
    double a3=0;
    double volouterwindow3= (wnwo_3*who_3*(wwo_3- 0.0254));

    switch(wti_3){
    case 0 : {
        a3= wood*volouterwindow3;break;
    }
    case 1 : {
        a3= alum*volouterwindow3;break;
    }
    case 2 : {
        a3= upvc*volouterwindow3;
    }
    }


    //inner window
    double b1=0;
    double volinnerwindow1 = (wnwi_1*whi_1*(wwi_1- 0.0254));

    switch(wti_1){
    case 0 : {
        b1= wood*volinnerwindow1;break;
    }
    case 1 : {
        b1= alum*volinnerwindow1;break;
    }
    case 2 : {
        b1= upvc*volinnerwindow1;
    }
    }

    //inner window for floor 2
    double b2=0;
    double volinnerwindow2 = (wnwi_2*whi_2*(wwi_2- 0.0254));

    switch(wti_2){
    case 0 : {
        b2= wood*volinnerwindow2;break;
    }
    case 1 : {
        b2= alum*volinnerwindow2;break;
    }
    case 2 : {
        b2= upvc*volinnerwindow2;
    }
    }
    //inner window for floor 3
    double b3 = 0;
    double volinnerwindow3= (wnwi_3*whi_3*(wwi_3- 0.0254));

    switch(wti_3){
    case 0 : {
        b3= wood*volinnerwindow3;break;
    }
    case 1 : {
        b3= alum*volinnerwindow3;break;
    }
    case 2 : {
        b3= upvc*volinnerwindow3;
    }
    }

    //Total cost for windows
    double wcost = a1+a2+a3+b1+b2+b3;
    return wcost;
}

//display
void HCCE::on_PB20_3_clicked()
{
    dno_2=0,dni_2=0,wno_2=0,wni_2=0;
    who_2=0,whi_2=0,wnwo_2=0,wnwi_2=0;
    dho_2=0,dhi_2=0,dwo_2=0,dwi_2=0;
    st_2=0,sa_2=0;
    wti_2=0,wto_2=0,bd_2=0;
    dno_3=0,dni_3=0,wno_3=0,wni_3=0;
    who_3=0,whi_3=0,wnwo_3=0,wnwi_3=0;
    dho_3=0,dhi_3=0,dwo_3=0,dwi_3=0;
    st_3=0,sa_3=0;
    wti_3=0,wto_3=0,bd_3=0;

}

void HCCE::on_PB20_2_clicked()
{
    dno_3=0,dni_3=0,wno_3=0,wni_3=0;
    who_3=0,whi_3=0,wnwo_3=0,wnwi_3=0;
    dho_3=0,dhi_3=0,dwo_3=0,dwi_3=0;
    st_3=0,sa_3=0;
    wti_3=0,wto_3=0,bd_3=0;
}

void HCCE::on_pushButton_3_clicked()
{
    ui->ldpccost->setNum(costdpc);
}


void HCCE::on_pushButton_6_clicked()
{
    ui->lwallcost->setNum(costwall);
}

void HCCE::on_pushButton_5_clicked()
{
    ui->lstrcost->setNum(coststr);
}

void HCCE::on_pushButton_4_clicked()
{
    ui->lstcost->setNum(costst);
}

void HCCE::on_pushButton_7_clicked()
{
    ui->lfrcost->setNum(costfur);
}

void HCCE::on_pushButton_8_clicked()
{
    ui->lfincost->setNum(ha);
}



void HCCE::on_pushButton_9_clicked()
{
    QString user_name=ui->lineEdit_2->text();
    QString pass=ui->lineEdit->text();
    if(user_name=="trytest" && pass=="test"){
      ui->label_23->setNum(2);
    }
    else{
        QMessageBox::warning(this,"login","username amd password is incorrect");
    }
    //admin sec;
    //sec.setModal(true);
    //sec.exec();
}

void HCCE::on_PB21_2_clicked()
{
    ui->stackedWidget->setCurrentIndex(6);
}




void HCCE::on_FTB_valueChanged(double arg1)
{
     footbreadth = arg1;
}

void HCCE::on_FTL_valueChanged(double arg1)
{
    footlen = arg1;
}





