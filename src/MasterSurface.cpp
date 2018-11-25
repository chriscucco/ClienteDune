#ifndef MASTERSURFACE_CPP_
#define MASTERSURFACE_CPP_

#include "MasterSurface.h"


MasterSurface::MasterSurface(){
	this->init_trike();
	this->init_button_centrodeconstruccion();
	this->init_button_cosechadora();
	this->init_button_cuartelatreides();
	this->init_button_cuartelharkonnen();
	this->init_button_cuartelordos();
	this->init_button_desviador();
	this->init_button_devastador();
	this->init_button_fabricaligera();
	this->init_button_fabricapesada();
	this->init_button_fremen();
	this->init_button_infanterialigera();
	this->init_button_infanteriapesada();
	this->init_button_palacio();
	this->init_button_raider();
	this->init_button_refineria();
	this->init_button_sardaukar();
	this->init_button_silo();
	this->init_button_sonictank();
	this->init_button_tanque();
	this->init_button_trampadeaire();
	this->init_button_trike();
	this->init_centrodeconstruccion();
	this->init_cima();
	this->init_cuartelatreides();
}


void MasterSurface::init_trike(){
	std::shared_ptr<Surface> s1(new Surface("imgs/Vehiculos/Trike/1.png"));
	std::shared_ptr<Surface> s2(new Surface("imgs/Vehiculos/Trike/2.png"));
	std::shared_ptr<Surface> s3(new Surface("imgs/Vehiculos/Trike/3.png"));
	std::shared_ptr<Surface> s4(new Surface("imgs/Vehiculos/Trike/4.png"));
	std::shared_ptr<Surface> s5(new Surface("imgs/Vehiculos/Trike/5.png"));
	std::shared_ptr<Surface> s6(new Surface("imgs/Vehiculos/Trike/6.png"));
	std::shared_ptr<Surface> s7(new Surface("imgs/Vehiculos/Trike/7.png"));
	std::shared_ptr<Surface> s8(new Surface("imgs/Vehiculos/Trike/8.png"));
	this->trike.push_back(s1);
	this->trike.push_back(s2);
	this->trike.push_back(s3);
	this->trike.push_back(s4);
	this->trike.push_back(s5);
	this->trike.push_back(s6);
	this->trike.push_back(s7);
	this->trike.push_back(s8);
}


std::vector<std::shared_ptr<Surface>> MasterSurface::get_trike_surface(){
	return this->trike;
}


void MasterSurface::init_button_centrodeconstruccion(){
	std::shared_ptr<Surface> s(new Surface("imgs/Botones/CentroDeConstruccion.png"));
	this->button_centrodeconstruccion=s;
}

std::shared_ptr<Surface> MasterSurface::get_button_centrodeconstruccion_surface(){
	return this->button_centrodeconstruccion;
}

void MasterSurface::init_button_cosechadora(){
	std::shared_ptr<Surface> s(new Surface("imgs/Botones/Cosechadora.png"));
	this->button_cosechadora=s;
}

std::shared_ptr<Surface> MasterSurface::get_button_cosechadora_surface(){
	return this->button_cosechadora;
}


void MasterSurface::init_button_cuartelatreides(){
	std::shared_ptr<Surface> s(new Surface("imgs/Botones/CuartelAtreides.png"));
	this->button_cuartelatreides=s;
}

std::shared_ptr<Surface> MasterSurface::get_button_cuartelatreides_surface(){
	return this->button_cuartelatreides;
}


void MasterSurface::init_button_cuartelharkonnen(){
	std::shared_ptr<Surface> s(new Surface("imgs/Botones/CuartelHarkonnen.png"));
	this->button_cuartelharkonnen=s;
}

std::shared_ptr<Surface> MasterSurface::get_button_cuartelharkonnen_surface(){
	return this->button_cuartelharkonnen;
}


void MasterSurface::init_button_cuartelordos(){
	std::shared_ptr<Surface> s(new Surface("imgs/Botones/CuartelOrdos.png"));
	this->button_cuartelordos=s;
}

std::shared_ptr<Surface> MasterSurface::get_button_cuartelordos_surface(){
	return this->button_cuartelordos;
}


void MasterSurface::init_button_desviador(){
	std::shared_ptr<Surface> s(new Surface("imgs/Botones/Desviador.png"));
	this->button_desviador=s;
}

std::shared_ptr<Surface> MasterSurface::get_button_desviador_surface(){
	return this->button_desviador;
}


void MasterSurface::init_button_devastador(){
	std::shared_ptr<Surface> s(new Surface("imgs/Botones/Devastador.png"));
	this->button_devastador=s;
}


std::shared_ptr<Surface> MasterSurface::get_button_devastador_surface(){
	return this->button_devastador;
}


void MasterSurface::init_button_fabricaligera(){
	std::shared_ptr<Surface> s(new Surface("imgs/Botones/FabricaLigera.png"));
	this->button_fabricaligera=s;
}


std::shared_ptr<Surface> MasterSurface::get_button_fabricaligera_surface(){
	return this->button_fabricaligera;
}

void MasterSurface::init_button_fabricapesada(){
	std::shared_ptr<Surface> s(new Surface("imgs/Botones/FabricaPesada.png"));
	this->button_fabricapesada=s;
}


std::shared_ptr<Surface> MasterSurface::get_button_fabricapesada_surface(){
	return this->button_fabricapesada;
}


void MasterSurface::init_button_fremen(){
	std::shared_ptr<Surface> s(new Surface("imgs/Botones/Fremen.png"));
	this->button_fremen=s;
}


std::shared_ptr<Surface> MasterSurface::get_button_fremen_surface(){
	return this->button_fremen;
}


void MasterSurface::init_button_infanterialigera(){
	std::shared_ptr<Surface> s(new Surface("imgs/Botones/InfanteriaLigera.png"));
	this->button_infanterialigera=s;
}


std::shared_ptr<Surface> MasterSurface::get_button_infanterialigera_surface(){
	return this->button_infanterialigera;
}

void MasterSurface::init_button_infanteriapesada(){
	std::shared_ptr<Surface> s(new Surface("imgs/Botones/InfanteriaPesada.png"));
	this->button_infanteriapesada=s;
}


std::shared_ptr<Surface> MasterSurface::get_button_infanteriapesada_surface(){
	return this->button_infanteriapesada;
}


void MasterSurface::init_button_palacio(){
	std::shared_ptr<Surface> s(new Surface("imgs/Botones/Palacio.png"));
	this->button_palacio=s;
}


std::shared_ptr<Surface> MasterSurface::get_button_palacio_surface(){
	return this->button_palacio;
}


void MasterSurface::init_button_raider(){
	std::shared_ptr<Surface> s(new Surface("imgs/Botones/Raider.png"));
	this->button_raider=s;
}


std::shared_ptr<Surface> MasterSurface::get_button_raider_surface(){
	return this->button_raider;
}


void MasterSurface::init_button_refineria(){
	std::shared_ptr<Surface> s(new Surface("imgs/Botones/Refineria.png"));
	this->button_refineria=s;
}


std::shared_ptr<Surface> MasterSurface::get_button_refineria_surface(){
	return this->button_refineria;
}


void MasterSurface::init_button_sardaukar(){
	std::shared_ptr<Surface> s(new Surface("imgs/Botones/Sardaukar.png"));
	this->button_sardaukar=s;
}


std::shared_ptr<Surface> MasterSurface::get_button_sardaukar_surface(){
	return this->button_sardaukar;
}


void MasterSurface::init_button_silo(){
	std::shared_ptr<Surface> s(new Surface("imgs/Botones/Silo.png"));
	this->button_silo=s;
}


std::shared_ptr<Surface> MasterSurface::get_button_silo_surface(){
	return this->button_silo;
}


void MasterSurface::init_button_sonictank(){
	std::shared_ptr<Surface> s(new Surface("imgs/Botones/TanqueSonico.png"));
	this->button_sonictank=s;
}


std::shared_ptr<Surface> MasterSurface::get_button_sonictank_surface(){
	return this->button_sonictank;
}


void MasterSurface::init_button_tanque(){
	std::shared_ptr<Surface> s(new Surface("imgs/Botones/Tanque.png"));
	this->button_tanque=s;
}


std::shared_ptr<Surface> MasterSurface::get_button_tanque_surface(){
	return this->button_tanque;
}

void MasterSurface::init_button_trampadeaire(){
	std::shared_ptr<Surface> s(new Surface("imgs/Botones/TrampaDeAire.png"));
	this->button_trampadeaire=s;
}


std::shared_ptr<Surface> MasterSurface::get_button_trampadeaire_surface(){
	return this->button_trampadeaire;
}

void MasterSurface::init_button_trike(){
	std::shared_ptr<Surface> s(new Surface("imgs/Botones/Trike.png"));
	this->button_trike=s;
}


std::shared_ptr<Surface> MasterSurface::get_button_trike_surface(){
	return this->button_trike;
}


void MasterSurface::init_centrodeconstruccion(){
	std::shared_ptr<Surface> s(new Surface("imgs/Edificios/CentroDeConstruccion.png"));
	this->centrodeconstruccion=s;
}


std::shared_ptr<Surface> MasterSurface::get_centrodeconstruccion_surface(){
	return this->centrodeconstruccion;
}


void MasterSurface::init_cuartelatreides(){
	std::shared_ptr<Surface> s(new Surface("imgs/Edificios/CuartelAtreides.png"));
	this->cuartelatreides=s;
}


std::shared_ptr<Surface> MasterSurface::get_cuartelatreides_surface(){
	return this->cuartelatreides;
}


void MasterSurface::init_cima(){
	std::shared_ptr<Surface> s(new Surface("imgs/Terreno/Cima.png"));
	this->cima=s;
}


std::shared_ptr<Surface> MasterSurface::get_cima_surface(){
	return this->cima;
}

MasterSurface::~MasterSurface(){}


#endif