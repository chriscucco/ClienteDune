#ifndef MASTERSURFACE_CPP_
#define MASTERSURFACE_CPP_
#include "MasterSurface.h"


MasterSurface::MasterSurface(){
	this->init_trike();
	this->init_cosechadora();
	this->init_desviador();
	this->init_devastador();
	this->init_raider();
	this->init_sonictank();
	this->init_tanque();
	this->init_fremen();
	this->init_infanterialigera();
	this->init_infanteriapesada();
	this->init_sardaukar();
	this->init_gusano();
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
	this->init_palacio();
	this->init_refineria();
	this->init_silo();
	this->init_trampadeaire();
	this->init_cima();
	this->init_duna();
	this->init_especiafuerte();
	this->init_especiasuave();
	this->init_precipicio();
	this->init_roca();
	this->init_cuartelatreides();
	this->init_cuartelharkonnen();
	this->init_cuartelordos();
	this->init_fabricaligera();
	this->init_fabricapesada();
	this->init_explosionpersonaje();
	this->init_explosionfuerte();
	this->init_explosiontanque();
	this->init_button_money();
	this->init_pointer();
	this->init_button_cima();
	this->init_button_duna();
	this->init_button_precipicio();
	this->init_button_especiafuerte();
	this->init_button_especiasuave();
	this->init_button_roca();
	this->init_button_save();
	this->init_button_cancel();
	this->init_hpointer();
	this->init_initmatch();
	this->init_button_charge();
}


void MasterSurface::init_explosionpersonaje(){
	std::shared_ptr<Surface> s1(new Surface("imgs/Explosion/ExplotaPersonaje/1.png"));
	std::shared_ptr<Surface> s2(new Surface("imgs/Explosion/ExplotaPersonaje/2.png"));
	std::shared_ptr<Surface> s3(new Surface("imgs/Explosion/ExplotaPersonaje/3.png"));
	std::shared_ptr<Surface> s4(new Surface("imgs/Explosion/ExplotaPersonaje/4.png"));
	std::shared_ptr<Surface> s5(new Surface("imgs/Explosion/ExplotaPersonaje/5.png"));
	std::shared_ptr<Surface> s6(new Surface("imgs/Explosion/ExplotaPersonaje/6.png"));
	std::shared_ptr<Surface> s7(new Surface("imgs/Explosion/ExplotaPersonaje/7.png"));
	this->explosionpersonaje.push_back(s1);
	this->explosionpersonaje.push_back(s2);
	this->explosionpersonaje.push_back(s3);
	this->explosionpersonaje.push_back(s4);
	this->explosionpersonaje.push_back(s5);
	this->explosionpersonaje.push_back(s6);
	this->explosionpersonaje.push_back(s7);
}


std::vector<std::shared_ptr<Surface>> MasterSurface::get_explosionpersonaje_surface(){
	return this->explosionpersonaje;
}


void MasterSurface::init_gusano(){
	std::shared_ptr<Surface> s1(new Surface("imgs/Gusano/1.png"));
	std::shared_ptr<Surface> s2(new Surface("imgs/Gusano/2.png"));
	std::shared_ptr<Surface> s3(new Surface("imgs/Gusano/3.png"));
	std::shared_ptr<Surface> s4(new Surface("imgs/Gusano/4.png"));
	std::shared_ptr<Surface> s5(new Surface("imgs/Gusano/5.png"));
	std::shared_ptr<Surface> s6(new Surface("imgs/Gusano/6.png"));
	std::shared_ptr<Surface> s7(new Surface("imgs/Gusano/7.png"));
	std::shared_ptr<Surface> s8(new Surface("imgs/Gusano/8.png"));
	std::shared_ptr<Surface> s9(new Surface("imgs/Gusano/9.png"));
	std::shared_ptr<Surface> s10(new Surface("imgs/Gusano/10.png"));
	this->gusano.push_back(s1);
	this->gusano.push_back(s2);
	this->gusano.push_back(s3);
	this->gusano.push_back(s4);
	this->gusano.push_back(s5);
	this->gusano.push_back(s6);
	this->gusano.push_back(s7);
	this->gusano.push_back(s8);
	this->gusano.push_back(s9);
	this->gusano.push_back(s10);
}


std::vector<std::shared_ptr<Surface>> MasterSurface::get_gusano_surface(){
	return this->gusano;
}


void MasterSurface::init_fremen(){	
	std::shared_ptr<Surface> s1(new Surface("imgs/Fremen/Movible/Arriba/1.png"));
	std::shared_ptr<Surface> s2(new Surface("imgs/Fremen/Movible/Arriba/2.png"));
	std::shared_ptr<Surface> s3(new Surface("imgs/Fremen/Movible/Derecha/1.png"));
	std::shared_ptr<Surface> s4(new Surface("imgs/Fremen/Movible/Derecha/2.png"));
	std::shared_ptr<Surface> s5(new Surface("imgs/Fremen/Movible/Abajo/1.png"));
	std::shared_ptr<Surface> s6(new Surface("imgs/Fremen/Movible/Abajo/2.png"));
	std::shared_ptr<Surface> s7(new Surface("imgs/Fremen/Movible/Izquierda/1.png"));
	std::shared_ptr<Surface> s8(new Surface("imgs/Fremen/Movible/Izquierda/2.png"));
	this->fremen.push_back(s1);
	this->fremen.push_back(s2);
	this->fremen.push_back(s3);
	this->fremen.push_back(s4);
	this->fremen.push_back(s5);
	this->fremen.push_back(s6);
	this->fremen.push_back(s7);
	this->fremen.push_back(s8);
	std::shared_ptr<Surface> s10(new Surface("imgs/Fremen/Ataque/Arriba/0.png"));
	std::shared_ptr<Surface> s11(new Surface("imgs/Fremen/Ataque/Arriba/1.png"));
	std::shared_ptr<Surface> s12(new Surface("imgs/Fremen/Ataque/Arriba/2.png"));
	std::shared_ptr<Surface> s13(new Surface("imgs/Fremen/Ataque/Arriba/3.png"));
	std::shared_ptr<Surface> s14(new Surface("imgs/Fremen/Ataque/Derecha/0.png"));
	std::shared_ptr<Surface> s15(new Surface("imgs/Fremen/Ataque/Derecha/1.png"));
	std::shared_ptr<Surface> s16(new Surface("imgs/Fremen/Ataque/Derecha/2.png"));
	std::shared_ptr<Surface> s17(new Surface("imgs/Fremen/Ataque/Derecha/3.png"));
	std::shared_ptr<Surface> s18(new Surface("imgs/Fremen/Ataque/Abajo/0.png"));
	std::shared_ptr<Surface> s19(new Surface("imgs/Fremen/Ataque/Abajo/1.png"));
	std::shared_ptr<Surface> s20(new Surface("imgs/Fremen/Ataque/Abajo/2.png"));
	std::shared_ptr<Surface> s21(new Surface("imgs/Fremen/Ataque/Abajo/3.png"));
	std::shared_ptr<Surface> s22(new Surface("imgs/Fremen/Ataque/Izquierda/0.png"));
	std::shared_ptr<Surface> s23(new Surface("imgs/Fremen/Ataque/Izquierda/1.png"));
	std::shared_ptr<Surface> s24(new Surface("imgs/Fremen/Ataque/Izquierda/2.png"));
	std::shared_ptr<Surface> s25(new Surface("imgs/Fremen/Ataque/Izquierda/3.png"));
	this->fremen_attack.push_back(s10);
	this->fremen_attack.push_back(s11);
	this->fremen_attack.push_back(s12);
	this->fremen_attack.push_back(s13);
	this->fremen_attack.push_back(s14);
	this->fremen_attack.push_back(s15);
	this->fremen_attack.push_back(s16);
	this->fremen_attack.push_back(s17);
	this->fremen_attack.push_back(s18);
	this->fremen_attack.push_back(s19);
	this->fremen_attack.push_back(s20);
	this->fremen_attack.push_back(s21);
	this->fremen_attack.push_back(s22);
	this->fremen_attack.push_back(s23);
	this->fremen_attack.push_back(s24);
	this->fremen_attack.push_back(s25);
}


std::vector<std::shared_ptr<Surface>> MasterSurface::get_fremen_surface(){
	return this->fremen;
}


std::vector<std::shared_ptr<Surface>> MasterSurface::get_fremenattack_surface(){
	return this->fremen_attack;
}


void MasterSurface::init_infanterialigera(){	
	std::shared_ptr<Surface> s1(new Surface("imgs/InfanteriaLigera/Movible/Arriba/1.png"));
	std::shared_ptr<Surface> s2(new Surface("imgs/InfanteriaLigera/Movible/Arriba/2.png"));
	std::shared_ptr<Surface> s3(new Surface("imgs/InfanteriaLigera/Movible/Derecha/1.png"));
	std::shared_ptr<Surface> s4(new Surface("imgs/InfanteriaLigera/Movible/Derecha/2.png"));
	std::shared_ptr<Surface> s5(new Surface("imgs/InfanteriaLigera/Movible/Abajo/1.png"));
	std::shared_ptr<Surface> s6(new Surface("imgs/InfanteriaLigera/Movible/Abajo/2.png"));
	std::shared_ptr<Surface> s7(new Surface("imgs/InfanteriaLigera/Movible/Izquierda/1.png"));
	std::shared_ptr<Surface> s8(new Surface("imgs/InfanteriaLigera/Movible/Izquierda/2.png"));
	this->infanterialigera.push_back(s1);
	this->infanterialigera.push_back(s2);
	this->infanterialigera.push_back(s3);
	this->infanterialigera.push_back(s4);
	this->infanterialigera.push_back(s5);
	this->infanterialigera.push_back(s6);
	this->infanterialigera.push_back(s7);
	this->infanterialigera.push_back(s8);
	std::shared_ptr<Surface> s10(new Surface("imgs/InfanteriaLigera/Ataque/Arriba/0.png"));
	std::shared_ptr<Surface> s11(new Surface("imgs/InfanteriaLigera/Ataque/Arriba/1.png"));
	std::shared_ptr<Surface> s12(new Surface("imgs/InfanteriaLigera/Ataque/Arriba/2.png"));
	std::shared_ptr<Surface> s13(new Surface("imgs/InfanteriaLigera/Ataque/Arriba/3.png"));
	std::shared_ptr<Surface> s14(new Surface("imgs/InfanteriaLigera/Ataque/Derecha/0.png"));
	std::shared_ptr<Surface> s15(new Surface("imgs/InfanteriaLigera/Ataque/Derecha/1.png"));
	std::shared_ptr<Surface> s16(new Surface("imgs/InfanteriaLigera/Ataque/Derecha/2.png"));
	std::shared_ptr<Surface> s17(new Surface("imgs/InfanteriaLigera/Ataque/Derecha/3.png"));
	std::shared_ptr<Surface> s18(new Surface("imgs/InfanteriaLigera/Ataque/Abajo/0.png"));
	std::shared_ptr<Surface> s19(new Surface("imgs/InfanteriaLigera/Ataque/Abajo/1.png"));
	std::shared_ptr<Surface> s20(new Surface("imgs/InfanteriaLigera/Ataque/Abajo/2.png"));
	std::shared_ptr<Surface> s21(new Surface("imgs/InfanteriaLigera/Ataque/Abajo/3.png"));
	std::shared_ptr<Surface> s22(new Surface("imgs/InfanteriaLigera/Ataque/Izquierda/0.png"));
	std::shared_ptr<Surface> s23(new Surface("imgs/InfanteriaLigera/Ataque/Izquierda/1.png"));
	std::shared_ptr<Surface> s24(new Surface("imgs/InfanteriaLigera/Ataque/Izquierda/2.png"));
	std::shared_ptr<Surface> s25(new Surface("imgs/InfanteriaLigera/Ataque/Izquierda/3.png"));
	this->infanterialigera_attack.push_back(s10);
	this->infanterialigera_attack.push_back(s11);
	this->infanterialigera_attack.push_back(s12);
	this->infanterialigera_attack.push_back(s13);
	this->infanterialigera_attack.push_back(s14);
	this->infanterialigera_attack.push_back(s15);
	this->infanterialigera_attack.push_back(s16);
	this->infanterialigera_attack.push_back(s17);
	this->infanterialigera_attack.push_back(s18);
	this->infanterialigera_attack.push_back(s19);
	this->infanterialigera_attack.push_back(s20);
	this->infanterialigera_attack.push_back(s21);
	this->infanterialigera_attack.push_back(s22);
	this->infanterialigera_attack.push_back(s23);
	this->infanterialigera_attack.push_back(s24);
	this->infanterialigera_attack.push_back(s25);
}


void MasterSurface::init_infanteriapesada(){
	std::shared_ptr<Surface> s1(new Surface("imgs/InfanteriaPesada/Movible/Arriba/1.png"));
	std::shared_ptr<Surface> s2(new Surface("imgs/InfanteriaPesada/Movible/Arriba/2.png"));
	std::shared_ptr<Surface> s3(new Surface("imgs/InfanteriaPesada/Movible/Derecha/1.png"));
	std::shared_ptr<Surface> s4(new Surface("imgs/InfanteriaPesada/Movible/Derecha/2.png"));
	std::shared_ptr<Surface> s5(new Surface("imgs/InfanteriaPesada/Movible/Abajo/1.png"));
	std::shared_ptr<Surface> s6(new Surface("imgs/InfanteriaPesada/Movible/Abajo/2.png"));
	std::shared_ptr<Surface> s7(new Surface("imgs/InfanteriaPesada/Movible/Izquierda/1.png"));
	std::shared_ptr<Surface> s8(new Surface("imgs/InfanteriaPesada/Movible/Izquierda/2.png"));
	this->infanteriapesada.push_back(s1);
	this->infanteriapesada.push_back(s2);
	this->infanteriapesada.push_back(s3);
	this->infanteriapesada.push_back(s4);
	this->infanteriapesada.push_back(s5);
	this->infanteriapesada.push_back(s6);
	this->infanteriapesada.push_back(s7);
	this->infanteriapesada.push_back(s8);
	std::shared_ptr<Surface> s10(new Surface("imgs/InfanteriaPesada/Ataque/Arriba/0.png"));
	std::shared_ptr<Surface> s11(new Surface("imgs/InfanteriaPesada/Ataque/Arriba/1.png"));
	std::shared_ptr<Surface> s12(new Surface("imgs/InfanteriaPesada/Ataque/Arriba/2.png"));
	std::shared_ptr<Surface> s13(new Surface("imgs/InfanteriaPesada/Ataque/Arriba/3.png"));
	std::shared_ptr<Surface> s14(new Surface("imgs/InfanteriaPesada/Ataque/Derecha/0.png"));
	std::shared_ptr<Surface> s15(new Surface("imgs/InfanteriaPesada/Ataque/Derecha/1.png"));
	std::shared_ptr<Surface> s16(new Surface("imgs/InfanteriaPesada/Ataque/Derecha/2.png"));
	std::shared_ptr<Surface> s17(new Surface("imgs/InfanteriaPesada/Ataque/Derecha/3.png"));
	std::shared_ptr<Surface> s18(new Surface("imgs/InfanteriaPesada/Ataque/Abajo/0.png"));
	std::shared_ptr<Surface> s19(new Surface("imgs/InfanteriaPesada/Ataque/Abajo/1.png"));
	std::shared_ptr<Surface> s20(new Surface("imgs/InfanteriaPesada/Ataque/Abajo/2.png"));
	std::shared_ptr<Surface> s21(new Surface("imgs/InfanteriaPesada/Ataque/Abajo/3.png"));
	std::shared_ptr<Surface> s22(new Surface("imgs/InfanteriaPesada/Ataque/Izquierda/0.png"));
	std::shared_ptr<Surface> s23(new Surface("imgs/InfanteriaPesada/Ataque/Izquierda/1.png"));
	std::shared_ptr<Surface> s24(new Surface("imgs/InfanteriaPesada/Ataque/Izquierda/2.png"));
	std::shared_ptr<Surface> s25(new Surface("imgs/InfanteriaPesada/Ataque/Izquierda/3.png"));
	this->infanteriapesada_attack.push_back(s10);
	this->infanteriapesada_attack.push_back(s11);
	this->infanteriapesada_attack.push_back(s12);
	this->infanteriapesada_attack.push_back(s13);
	this->infanteriapesada_attack.push_back(s14);
	this->infanteriapesada_attack.push_back(s15);
	this->infanteriapesada_attack.push_back(s16);
	this->infanteriapesada_attack.push_back(s17);
	this->infanteriapesada_attack.push_back(s18);
	this->infanteriapesada_attack.push_back(s19);
	this->infanteriapesada_attack.push_back(s20);
	this->infanteriapesada_attack.push_back(s21);
	this->infanteriapesada_attack.push_back(s22);
	this->infanteriapesada_attack.push_back(s23);
	this->infanteriapesada_attack.push_back(s24);
	this->infanteriapesada_attack.push_back(s25);
}


std::vector<std::shared_ptr<Surface>> MasterSurface::get_infanterialigera_surface(){
	return this->infanterialigera;
}


std::vector<std::shared_ptr<Surface>> MasterSurface::get_infanterialigeraattack_surface(){
	return this->infanterialigera_attack;
}


std::vector<std::shared_ptr<Surface>> MasterSurface::get_infanteriapesada_surface(){
	return this->infanteriapesada;
}


std::vector<std::shared_ptr<Surface>> MasterSurface::get_infanteriapesadaattack_surface(){
	return this->infanteriapesada_attack;
}


void MasterSurface::init_sardaukar(){
	std::shared_ptr<Surface> s1(new Surface("imgs/Sardaukar/Movible/Arriba/1.png"));
	std::shared_ptr<Surface> s2(new Surface("imgs/Sardaukar/Movible/Arriba/2.png"));
	std::shared_ptr<Surface> s3(new Surface("imgs/Sardaukar/Movible/Derecha/1.png"));
	std::shared_ptr<Surface> s4(new Surface("imgs/Sardaukar/Movible/Derecha/2.png"));
	std::shared_ptr<Surface> s5(new Surface("imgs/Sardaukar/Movible/Abajo/1.png"));
	std::shared_ptr<Surface> s6(new Surface("imgs/Sardaukar/Movible/Abajo/2.png"));
	std::shared_ptr<Surface> s7(new Surface("imgs/Sardaukar/Movible/Izquierda/1.png"));
	std::shared_ptr<Surface> s8(new Surface("imgs/Sardaukar/Movible/Izquierda/2.png"));
	this->sardaukar.push_back(s1);
	this->sardaukar.push_back(s2);
	this->sardaukar.push_back(s3);
	this->sardaukar.push_back(s4);
	this->sardaukar.push_back(s5);
	this->sardaukar.push_back(s6);
	this->sardaukar.push_back(s7);
	this->sardaukar.push_back(s8);
	std::shared_ptr<Surface> s10(new Surface("imgs/Sardaukar/Ataque/Arriba/0.png"));
	std::shared_ptr<Surface> s11(new Surface("imgs/Sardaukar/Ataque/Arriba/1.png"));
	std::shared_ptr<Surface> s12(new Surface("imgs/Sardaukar/Ataque/Arriba/2.png"));
	std::shared_ptr<Surface> s13(new Surface("imgs/Sardaukar/Ataque/Arriba/3.png"));
	std::shared_ptr<Surface> s14(new Surface("imgs/Sardaukar/Ataque/Derecha/0.png"));
	std::shared_ptr<Surface> s15(new Surface("imgs/Sardaukar/Ataque/Derecha/1.png"));
	std::shared_ptr<Surface> s16(new Surface("imgs/Sardaukar/Ataque/Derecha/2.png"));
	std::shared_ptr<Surface> s17(new Surface("imgs/Sardaukar/Ataque/Derecha/3.png"));
	std::shared_ptr<Surface> s18(new Surface("imgs/Sardaukar/Ataque/Abajo/0.png"));
	std::shared_ptr<Surface> s19(new Surface("imgs/Sardaukar/Ataque/Abajo/1.png"));
	std::shared_ptr<Surface> s20(new Surface("imgs/Sardaukar/Ataque/Abajo/2.png"));
	std::shared_ptr<Surface> s21(new Surface("imgs/Sardaukar/Ataque/Abajo/3.png"));
	std::shared_ptr<Surface> s22(new Surface("imgs/Sardaukar/Ataque/Izquierda/0.png"));
	std::shared_ptr<Surface> s23(new Surface("imgs/Sardaukar/Ataque/Izquierda/1.png"));
	std::shared_ptr<Surface> s24(new Surface("imgs/Sardaukar/Ataque/Izquierda/2.png"));
	std::shared_ptr<Surface> s25(new Surface("imgs/Sardaukar/Ataque/Izquierda/3.png"));
	this->sardaukar_attack.push_back(s10);
	this->sardaukar_attack.push_back(s11);
	this->sardaukar_attack.push_back(s12);
	this->sardaukar_attack.push_back(s13);
	this->sardaukar_attack.push_back(s14);
	this->sardaukar_attack.push_back(s15);
	this->sardaukar_attack.push_back(s16);
	this->sardaukar_attack.push_back(s17);
	this->sardaukar_attack.push_back(s18);
	this->sardaukar_attack.push_back(s19);
	this->sardaukar_attack.push_back(s20);
	this->sardaukar_attack.push_back(s21);
	this->sardaukar_attack.push_back(s22);
	this->sardaukar_attack.push_back(s23);
	this->sardaukar_attack.push_back(s24);
	this->sardaukar_attack.push_back(s25);
}


std::vector<std::shared_ptr<Surface>> MasterSurface::get_sardaukar_surface(){
	return this->sardaukar;
}


std::vector<std::shared_ptr<Surface>> MasterSurface::get_sardaukarattack_surface(){
	return this->sardaukar_attack;
}


void MasterSurface::init_explosionfuerte(){
	std::shared_ptr<Surface> s1(new Surface("imgs/Explosion/ExplosionFuerte/1.png"));
	std::shared_ptr<Surface> s2(new Surface("imgs/Explosion/ExplosionFuerte/2.png"));
	std::shared_ptr<Surface> s3(new Surface("imgs/Explosion/ExplosionFuerte/3.png"));
	std::shared_ptr<Surface> s4(new Surface("imgs/Explosion/ExplosionFuerte/4.png"));
	std::shared_ptr<Surface> s5(new Surface("imgs/Explosion/ExplosionFuerte/5.png"));
	std::shared_ptr<Surface> s6(new Surface("imgs/Explosion/ExplosionFuerte/6.png"));
	std::shared_ptr<Surface> s7(new Surface("imgs/Explosion/ExplosionFuerte/7.png"));
	std::shared_ptr<Surface> s8(new Surface("imgs/Explosion/ExplosionFuerte/8.png"));
	std::shared_ptr<Surface> s9(new Surface("imgs/Explosion/ExplosionFuerte/9.png"));
	std::shared_ptr<Surface> s10(new Surface("imgs/Explosion/ExplosionFuerte/10.png"));
	std::shared_ptr<Surface> s11(new Surface("imgs/Explosion/ExplosionFuerte/11.png"));
	std::shared_ptr<Surface> s12(new Surface("imgs/Explosion/ExplosionFuerte/12.png"));
	std::shared_ptr<Surface> s13(new Surface("imgs/Explosion/ExplosionFuerte/13.png"));
	std::shared_ptr<Surface> s14(new Surface("imgs/Explosion/ExplosionFuerte/14.png"));
	std::shared_ptr<Surface> s15(new Surface("imgs/Explosion/ExplosionFuerte/15.png"));
	std::shared_ptr<Surface> s16(new Surface("imgs/Explosion/ExplosionFuerte/16.png"));
	this->explosionfuerte.push_back(s1);
	this->explosionfuerte.push_back(s2);
	this->explosionfuerte.push_back(s3);
	this->explosionfuerte.push_back(s4);
	this->explosionfuerte.push_back(s5);
	this->explosionfuerte.push_back(s6);
	this->explosionfuerte.push_back(s7);
	this->explosionfuerte.push_back(s8);
	this->explosionfuerte.push_back(s9);
	this->explosionfuerte.push_back(s10);
	this->explosionfuerte.push_back(s11);
	this->explosionfuerte.push_back(s12);
	this->explosionfuerte.push_back(s13);
	this->explosionfuerte.push_back(s14);
	this->explosionfuerte.push_back(s15);
	this->explosionfuerte.push_back(s16);
}


std::vector<std::shared_ptr<Surface>> MasterSurface::get_explosionfuerte_surface(){
	return this->explosionfuerte;
}


void MasterSurface::init_explosiontanque(){
	std::shared_ptr<Surface> s1(new Surface("imgs/Explosion/ExplosionTanque/1.png"));
	std::shared_ptr<Surface> s2(new Surface("imgs/Explosion/ExplosionTanque/2.png"));
	std::shared_ptr<Surface> s3(new Surface("imgs/Explosion/ExplosionTanque/3.png"));
	std::shared_ptr<Surface> s4(new Surface("imgs/Explosion/ExplosionTanque/4.png"));
	std::shared_ptr<Surface> s5(new Surface("imgs/Explosion/ExplosionTanque/5.png"));
	std::shared_ptr<Surface> s6(new Surface("imgs/Explosion/ExplosionTanque/6.png"));
	std::shared_ptr<Surface> s7(new Surface("imgs/Explosion/ExplosionTanque/7.png"));
	std::shared_ptr<Surface> s8(new Surface("imgs/Explosion/ExplosionTanque/8.png"));
	std::shared_ptr<Surface> s9(new Surface("imgs/Explosion/ExplosionTanque/9.png"));
	std::shared_ptr<Surface> s10(new Surface("imgs/Explosion/ExplosionTanque/10.png"));
	std::shared_ptr<Surface> s11(new Surface("imgs/Explosion/ExplosionTanque/11.png"));
	std::shared_ptr<Surface> s12(new Surface("imgs/Explosion/ExplosionTanque/12.png"));
	std::shared_ptr<Surface> s13(new Surface("imgs/Explosion/ExplosionTanque/13.png"));
	std::shared_ptr<Surface> s14(new Surface("imgs/Explosion/ExplosionTanque/14.png"));
	this->explosiontanque.push_back(s1);
	this->explosiontanque.push_back(s2);
	this->explosiontanque.push_back(s3);
	this->explosiontanque.push_back(s4);
	this->explosiontanque.push_back(s5);
	this->explosiontanque.push_back(s6);
	this->explosiontanque.push_back(s7);
	this->explosiontanque.push_back(s8);
	this->explosiontanque.push_back(s9);
	this->explosiontanque.push_back(s10);
	this->explosiontanque.push_back(s11);
	this->explosiontanque.push_back(s12);
	this->explosiontanque.push_back(s13);
	this->explosiontanque.push_back(s14);
}


std::vector<std::shared_ptr<Surface>> MasterSurface::get_explosiontanque_surface(){
	return this->explosiontanque;
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


void MasterSurface::init_cosechadora(){
	std::shared_ptr<Surface> s1(new Surface("imgs/Vehiculos/Cosechadora/1.png"));
	std::shared_ptr<Surface> s2(new Surface("imgs/Vehiculos/Cosechadora/2.png"));
	std::shared_ptr<Surface> s3(new Surface("imgs/Vehiculos/Cosechadora/3.png"));
	std::shared_ptr<Surface> s4(new Surface("imgs/Vehiculos/Cosechadora/4.png"));
	std::shared_ptr<Surface> s5(new Surface("imgs/Vehiculos/Cosechadora/5.png"));
	std::shared_ptr<Surface> s6(new Surface("imgs/Vehiculos/Cosechadora/6.png"));
	std::shared_ptr<Surface> s7(new Surface("imgs/Vehiculos/Cosechadora/7.png"));
	std::shared_ptr<Surface> s8(new Surface("imgs/Vehiculos/Cosechadora/8.png"));
	this->cosechadora.push_back(s1);
	this->cosechadora.push_back(s2);
	this->cosechadora.push_back(s3);
	this->cosechadora.push_back(s4);
	this->cosechadora.push_back(s5);
	this->cosechadora.push_back(s6);
	this->cosechadora.push_back(s7);
	this->cosechadora.push_back(s8);
}


std::vector<std::shared_ptr<Surface>> MasterSurface::get_cosechadora_surface(){
	return this->cosechadora;
}


void MasterSurface::init_desviador(){
	std::shared_ptr<Surface> s1(new Surface("imgs/Vehiculos/Desviador/1.png"));
	std::shared_ptr<Surface> s2(new Surface("imgs/Vehiculos/Desviador/2.png"));
	std::shared_ptr<Surface> s3(new Surface("imgs/Vehiculos/Desviador/3.png"));
	std::shared_ptr<Surface> s4(new Surface("imgs/Vehiculos/Desviador/4.png"));
	std::shared_ptr<Surface> s5(new Surface("imgs/Vehiculos/Desviador/5.png"));
	std::shared_ptr<Surface> s6(new Surface("imgs/Vehiculos/Desviador/6.png"));
	std::shared_ptr<Surface> s7(new Surface("imgs/Vehiculos/Desviador/7.png"));
	std::shared_ptr<Surface> s8(new Surface("imgs/Vehiculos/Desviador/8.png"));
	this->desviador.push_back(s1);
	this->desviador.push_back(s2);
	this->desviador.push_back(s3);
	this->desviador.push_back(s4);
	this->desviador.push_back(s5);
	this->desviador.push_back(s6);
	this->desviador.push_back(s7);
	this->desviador.push_back(s8);
}


std::vector<std::shared_ptr<Surface>> MasterSurface::get_desviador_surface(){
	return this->desviador;
}


void MasterSurface::init_devastador(){
	std::shared_ptr<Surface> s1(new Surface("imgs/Vehiculos/Devastador/1.png"));
	std::shared_ptr<Surface> s2(new Surface("imgs/Vehiculos/Devastador/2.png"));
	std::shared_ptr<Surface> s3(new Surface("imgs/Vehiculos/Devastador/3.png"));
	std::shared_ptr<Surface> s4(new Surface("imgs/Vehiculos/Devastador/4.png"));
	std::shared_ptr<Surface> s5(new Surface("imgs/Vehiculos/Devastador/5.png"));
	std::shared_ptr<Surface> s6(new Surface("imgs/Vehiculos/Devastador/6.png"));
	std::shared_ptr<Surface> s7(new Surface("imgs/Vehiculos/Devastador/7.png"));
	std::shared_ptr<Surface> s8(new Surface("imgs/Vehiculos/Devastador/8.png"));
	this->devastador.push_back(s1);
	this->devastador.push_back(s2);
	this->devastador.push_back(s3);
	this->devastador.push_back(s4);
	this->devastador.push_back(s5);
	this->devastador.push_back(s6);
	this->devastador.push_back(s7);
	this->devastador.push_back(s8);
}


std::vector<std::shared_ptr<Surface>> MasterSurface::get_devastador_surface(){
	return this->devastador;
}


void MasterSurface::init_raider(){
	std::shared_ptr<Surface> s1(new Surface("imgs/Vehiculos/Raider/1.png"));
	std::shared_ptr<Surface> s2(new Surface("imgs/Vehiculos/Raider/2.png"));
	std::shared_ptr<Surface> s3(new Surface("imgs/Vehiculos/Raider/3.png"));
	std::shared_ptr<Surface> s4(new Surface("imgs/Vehiculos/Raider/4.png"));
	std::shared_ptr<Surface> s5(new Surface("imgs/Vehiculos/Raider/5.png"));
	std::shared_ptr<Surface> s6(new Surface("imgs/Vehiculos/Raider/6.png"));
	std::shared_ptr<Surface> s7(new Surface("imgs/Vehiculos/Raider/7.png"));
	std::shared_ptr<Surface> s8(new Surface("imgs/Vehiculos/Raider/8.png"));
	this->raider.push_back(s1);
	this->raider.push_back(s2);
	this->raider.push_back(s3);
	this->raider.push_back(s4);
	this->raider.push_back(s5);
	this->raider.push_back(s6);
	this->raider.push_back(s7);
	this->raider.push_back(s8);
}


std::vector<std::shared_ptr<Surface>> MasterSurface::get_raider_surface(){
	return this->raider;
}


void MasterSurface::init_sonictank(){
	std::shared_ptr<Surface> s1(new Surface("imgs/Vehiculos/SonicTank/1.png"));
	std::shared_ptr<Surface> s2(new Surface("imgs/Vehiculos/SonicTank/2.png"));
	std::shared_ptr<Surface> s3(new Surface("imgs/Vehiculos/SonicTank/3.png"));
	std::shared_ptr<Surface> s4(new Surface("imgs/Vehiculos/SonicTank/4.png"));
	std::shared_ptr<Surface> s5(new Surface("imgs/Vehiculos/SonicTank/5.png"));
	std::shared_ptr<Surface> s6(new Surface("imgs/Vehiculos/SonicTank/6.png"));
	std::shared_ptr<Surface> s7(new Surface("imgs/Vehiculos/SonicTank/7.png"));
	std::shared_ptr<Surface> s8(new Surface("imgs/Vehiculos/SonicTank/8.png"));
	this->sonictank.push_back(s1);
	this->sonictank.push_back(s2);
	this->sonictank.push_back(s3);
	this->sonictank.push_back(s4);
	this->sonictank.push_back(s5);
	this->sonictank.push_back(s6);
	this->sonictank.push_back(s7);
	this->sonictank.push_back(s8);
}


std::vector<std::shared_ptr<Surface>> MasterSurface::get_sonictank_surface(){
	return this->sonictank;
}


void MasterSurface::init_tanque(){
	std::shared_ptr<Surface> s1(new Surface("imgs/Vehiculos/Tanque/1.png"));
	std::shared_ptr<Surface> s2(new Surface("imgs/Vehiculos/Tanque/2.png"));
	std::shared_ptr<Surface> s3(new Surface("imgs/Vehiculos/Tanque/3.png"));
	std::shared_ptr<Surface> s4(new Surface("imgs/Vehiculos/Tanque/4.png"));
	std::shared_ptr<Surface> s5(new Surface("imgs/Vehiculos/Tanque/5.png"));
	std::shared_ptr<Surface> s6(new Surface("imgs/Vehiculos/Tanque/6.png"));
	std::shared_ptr<Surface> s7(new Surface("imgs/Vehiculos/Tanque/7.png"));
	std::shared_ptr<Surface> s8(new Surface("imgs/Vehiculos/Tanque/8.png"));
	this->tanque.push_back(s1);
	this->tanque.push_back(s2);
	this->tanque.push_back(s3);
	this->tanque.push_back(s4);
	this->tanque.push_back(s5);
	this->tanque.push_back(s6);
	this->tanque.push_back(s7);
	this->tanque.push_back(s8);
}


std::vector<std::shared_ptr<Surface>> MasterSurface::get_tanque_surface(){
	return this->tanque;
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


void MasterSurface::init_pointer(){
	std::shared_ptr<Surface> s(new Surface("imgs/point.png"));
	this->pointer=s;
}


std::shared_ptr<Surface> MasterSurface::get_pointer_surface(){
	return this->pointer;
}

void MasterSurface::init_hpointer(){
	std::shared_ptr<Surface> s(new Surface("imgs/hpoint.png"));
	this->hpointer=s;
}


std::shared_ptr<Surface> MasterSurface::get_hpointer_surface(){
	return this->hpointer;
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


void MasterSurface::init_button_roca(){
	std::shared_ptr<Surface> s(new Surface("imgs/Botones/Roca.png"));
	this->button_roca=s;
}


std::shared_ptr<Surface> MasterSurface::get_button_roca_surface(){
	return this->button_roca;
}


void MasterSurface::init_button_money(){
	std::shared_ptr<Surface> s(new Surface("imgs/Botones/Dinero.png"));
	this->button_money=s;
}


std::shared_ptr<Surface> MasterSurface::get_button_money_surface(){
	return this->button_money;
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


void MasterSurface::init_cuartelharkonnen(){
	std::shared_ptr<Surface> s(new Surface("imgs/Edificios/CuartelHarkonnen.png"));
	this->cuartelharkonnen=s;
}


std::shared_ptr<Surface> MasterSurface::get_cuartelharkonnen_surface(){
	return this->cuartelharkonnen;
}


void MasterSurface::init_fabricaligera(){
	std::shared_ptr<Surface> s(new Surface("imgs/Edificios/FabricaLigera.png"));
	this->fabricaligera=s;
}


std::shared_ptr<Surface> MasterSurface::get_fabricaligera_surface(){
	return this->fabricaligera;
}


void MasterSurface::init_fabricapesada(){
	std::shared_ptr<Surface> s(new Surface("imgs/Edificios/FabricaPesada.png"));
	this->fabricapesada=s;
}


std::shared_ptr<Surface> MasterSurface::get_fabricapesada_surface(){
	return this->fabricapesada;
}


void MasterSurface::init_cuartelordos(){
	std::shared_ptr<Surface> s(new Surface("imgs/Edificios/CuartelOrdos.png"));
	this->cuartelordos=s;
}


std::shared_ptr<Surface> MasterSurface::get_cuartelordos_surface(){
	return this->cuartelordos;
}


void MasterSurface::init_palacio(){
	std::shared_ptr<Surface> s(new Surface("imgs/Edificios/Palacio.png"));
	this->palacio=s;
}


std::shared_ptr<Surface> MasterSurface::get_palacio_surface(){
	return this->palacio;
}


void MasterSurface::init_refineria(){
	std::shared_ptr<Surface> s(new Surface("imgs/Edificios/Refineria.png"));
	this->refineria=s;
}


std::shared_ptr<Surface> MasterSurface::get_refineria_surface(){
	return this->refineria;
}


void MasterSurface::init_silo(){
	std::shared_ptr<Surface> s(new Surface("imgs/Edificios/Silo.png"));
	this->silo=s;
}


std::shared_ptr<Surface> MasterSurface::get_silo_surface(){
	return this->silo;
}


void MasterSurface::init_trampadeaire(){
	std::shared_ptr<Surface> s(new Surface("imgs/Edificios/TrampaDeAire.png"));
	this->trampadeaire=s;
}


std::shared_ptr<Surface> MasterSurface::get_trampadeaire_surface(){
	return this->trampadeaire;
}


void MasterSurface::init_cima(){
	std::shared_ptr<Surface> s(new Surface("imgs/Terreno/Cima.png"));
	this->cima=s;
}


std::shared_ptr<Surface> MasterSurface::get_cima_surface(){
	return this->cima;
}


void MasterSurface::init_duna(){
	std::shared_ptr<Surface> s(new Surface("imgs/Terreno/Duna.png"));
	this->duna=s;
}


std::shared_ptr<Surface> MasterSurface::get_duna_surface(){
	return this->duna;
}


void MasterSurface::init_especiafuerte(){
	std::shared_ptr<Surface> s(new Surface("imgs/Terreno/EspeciaFuerte.png"));
	this->especiafuerte=s;
}


std::shared_ptr<Surface> MasterSurface::get_especiafuerte_surface(){
	return this->especiafuerte;
}


void MasterSurface::init_especiasuave(){
	std::shared_ptr<Surface> s(new Surface("imgs/Terreno/EspeciaSuave.png"));
	this->especiasuave=s;
}


std::shared_ptr<Surface> MasterSurface::get_especiasuave_surface(){
	return this->especiasuave;
}


void MasterSurface::init_precipicio(){
	std::shared_ptr<Surface> s(new Surface("imgs/Terreno/Precipicio.png"));
	this->precipicio=s;
}


std::shared_ptr<Surface> MasterSurface::get_precipicio_surface(){
	return this->precipicio;
}


void MasterSurface::init_roca(){
	std::shared_ptr<Surface> s(new Surface("imgs/Terreno/Roca.png"));
	this->roca=s;
}


std::shared_ptr<Surface> MasterSurface::get_roca_surface(){
	return this->roca;
}


void MasterSurface::init_button_cima(){
	std::shared_ptr<Surface> s(new Surface("imgs/Botones/Cima.png"));
	this->button_cima=s;
}


std::shared_ptr<Surface> MasterSurface::get_button_cima_surface(){
	return this->button_cima;
}


void MasterSurface::init_button_especiafuerte(){
	std::shared_ptr<Surface> s(new Surface("imgs/Botones/EspeciaFuerte.png"));
	this->button_especiafuerte=s;
}


std::shared_ptr<Surface> MasterSurface::get_button_especiafuerte_surface(){
	return this->button_especiafuerte;
}


void MasterSurface::init_button_especiasuave(){
	std::shared_ptr<Surface> s(new Surface("imgs/Botones/EspeciaSuave.png"));
	this->button_especiasuave=s;
}


std::shared_ptr<Surface> MasterSurface::get_button_especiasuave_surface(){
	return this->button_especiasuave;
}


void MasterSurface::init_button_duna(){
	std::shared_ptr<Surface> s(new Surface("imgs/Botones/Duna.png"));
	this->button_duna=s;
}


std::shared_ptr<Surface> MasterSurface::get_button_duna_surface(){
	return this->button_duna;
}


void MasterSurface::init_button_precipicio(){
	std::shared_ptr<Surface> s(new Surface("imgs/Botones/Precipicio.png"));
	this->button_precipicio=s;
}


std::shared_ptr<Surface> MasterSurface::get_button_precipicio_surface(){
	return this->button_precipicio;
}


void MasterSurface::init_button_save(){
	std::shared_ptr<Surface> s(new Surface("imgs/Botones/Save.png"));
	this->button_save=s;
}


std::shared_ptr<Surface> MasterSurface::get_button_save_surface(){
	return this->button_save;
}


void MasterSurface::init_button_cancel(){
	std::shared_ptr<Surface> s(new Surface("imgs/Botones/Delete.png"));
	this->button_delete=s;
}


std::shared_ptr<Surface> MasterSurface::get_button_cancel_surface(){
	return this->button_delete;
}


void MasterSurface::init_button_charge(){
	std::shared_ptr<Surface> s(new Surface("imgs/Botones/Cargar.png"));
	this->button_charge=s;
}


std::shared_ptr<Surface> MasterSurface::get_button_charge_surface(){
	return this->button_charge;
}


void MasterSurface::init_initmatch(){
	std::shared_ptr<Surface> s(new Surface("terrain/InicioPartida.png"));
	this->initmatch=s;
}


std::shared_ptr<Surface> MasterSurface::get_initmatch_surface(){
	return this->initmatch;
}


MasterSurface::~MasterSurface(){}


#endif

