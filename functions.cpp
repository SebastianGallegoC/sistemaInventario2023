#include <iostream>
#include <vector>
using namespace std;

struct Producto {
  int codigo;
  string nombre;
  float precio;
  int stock;
};
vector<Producto> productos;
Producto producto;


struct Productoventa {
  string producto;
  string nombreVenta;
  int nroproducto;
  float precioVenta;
};
vector<Productoventa> productosventas;
Productoventa productoventa;

int ganancias;
string nnombre;
int  ncodigo, nstock;
float nprecio;
int flag,flagg;
int m;
string name;
int editar;
string usuario;
string contrasena;


void imprimirLinea() {
  cout << "|-------------------------------------------------|" << endl;
}

string usuarioAdmin = "Admin";
string contrasenaAdmin = "1234";

void imprimirMenu() {
  cout << "|-------------------------------------------------|" << endl;
  cout << "|                      MENÚ                       |" << endl;
  cout << "|------------------------|------------------------|" << endl;
  cout << "| 1. Registrar productos | 2. Buscar producto     |" << endl;
  cout << "| 3. Imprimir productos  | 4. Editar producto     |" << endl;
  cout << "| 5. Vender              | 6. Agregar stock       |" << endl;
  cout << "| 7. Imprimir ventas     | 8. Salir               |" << endl;
  cout << "|------------------------|----------------------- |" << endl;
  cout << "|Ingrese el número segun la funcion que requiera: |" << endl;
  cout << "|-------------------------------------------------|" << endl;
  cin >> m;
  imprimirLinea();
}

void inicioSesion() {
  cout <<" Ingrese el usuario: ";
  cin >> usuario;
  imprimirLinea();
  cout <<" Ingrese la contraseña: ";
  cin >> contrasena;
  if(usuario == usuarioAdmin && contrasena == contrasenaAdmin) {
    imprimirMenu();
  }else{
    cout <<" Usuario o contraseña incorrectos, vuelva a intentarlo" << endl;
    imprimirLinea();
    inicioSesion();
  }
}


void agregarProducto() {
  cout << " Nombre del producto: ";
  cin >> producto.nombre;
  cout << " Precio del producto: ";
  cin >> producto.precio;
  cout << " Cuanto stock hay: ";
  cin >> producto.stock;
  cout << " Codigo del producto: ";
  cin >> producto.codigo;
  productos.push_back(producto);
  imprimirLinea();
  cout << "Quiere agregar otro producto? Si(1) -- No(2)"<< endl;
  cin >> flag;
}

void imprimirProductos() {
  imprimirLinea();
  for (const Producto &producto: productos) {
    cout << " Nombre del producto: "<< producto.nombre<< endl;
    cout << " precio del producto: "<< producto.precio<< endl;
    cout << " Stock: "<< producto.stock<< endl;
    cout << " Codigo del producto: "<< producto.codigo<< endl;
    imprimirLinea();
  }
}

void buscarProducto() {
  cout << " Ingrese el nombre del producto que quiere buscar: "<< endl;
  cin >> name;
  for(const Producto &producto: productos) {
    if(name == producto.nombre) {
      cout << " Precio del producto: "<< producto.precio<< endl;
      cout << " Stock: "<< producto.stock<< endl;
      cout << " Codigo del producto: "<< producto.codigo<< endl;
      imprimirLinea();
    }
  }
}

void bandera() {
  cout<<" Quiere volver a editar algo del producto? Si(1) - No(2)"<< endl;
  cin >> flagg;
}

void editarProducto() {
  string newnombre;
  float newprecio;
  int newstock;
  int newcodigo;
  imprimirLinea();
  buscarProducto();
  cout << " Seleccione que dato quiere editar"<< endl;
  flagg = 1;
  while(flagg == 1){
    cout << " 1. Actualizar nombre" << endl;
    cout << " 2. Actualizar precio" << endl;
    cout << " 3. Actualizar stock" << endl;
    cout << " 4. Actualizar codigo" << endl;
    cout << " 5. Volver al menú" << endl;
    cin >> editar;
    imprimirLinea();
    for (Producto &producto: productos) {
      if (name == producto.nombre) {
        switch (editar){
          case 1:
            cout << " Ingrese el nuevo nombre: ";
            cin >> newnombre;
            producto.nombre = newnombre;
            bandera();
            break;
          case 2:
            cout << " Ingrese el nuevo precio: ";
            cin >> newprecio;
            producto.precio = newprecio;
            bandera();
            break;
          case 3:
            cout << " Ingrese el nuevo stock: ";
            cin >> newstock;
            producto.stock = newstock;
            bandera();
            break;
          case 4: 
            cout << " Ingrese el nuevo codigo: ";
            cin >> newcodigo;
            producto.codigo = newcodigo;
            bandera();
            break;
          case 5:
             imprimirMenu();
        }
      }
    }
  }
  imprimirLinea();
}

void vender() {
  string nombretemp;
  int cproductotemp;
  flagg = 1;
  while(flagg == 1) {
    buscarProducto();
    for(Producto &producto: productos) {
      if (name == producto.nombre) {
        productoventa.producto = producto.nombre;
        cout << " Nombre del comprador: ";
        cin >> nombretemp;
        cout << " Cuántos "<< producto.nombre << " va a vender?"<< endl;
        cin >> cproductotemp;
        if(cproductotemp <= producto.stock) {
          productoventa.nombreVenta = nombretemp;
          productoventa.nroproducto = cproductotemp;
          producto.stock = producto.stock - productoventa.nroproducto;
          productoventa.precioVenta = productoventa.nroproducto * producto.precio;
          productosventas.push_back(productoventa);
          ganancias += productoventa.precioVenta;
          cout << " Se vendió  $"<< productoventa.precioVenta << endl;
          cout << " Venta realizada con EXITO " << endl;
          cout << " Sus ganancias actuales son $"<< ganancias << endl;
          imprimirLinea();
        }else{
          cout << "El stock no es suficiente"<< endl;
        }
      }
    }
    
    cout << " Quiere vender algo mas? Si(1) - No(2)" << endl;
    cin >> flagg;
  }
}

void comprarStock() {
  int csuma;
  cout << " Ingrese el nombre del producto que quiere buscar: "<< endl;
  cin >> name;
  for( Producto &producto: productos) {
    if(name == producto.nombre) {
      cout << " Cuanto stock quiere sumarle a "<< producto.nombre<< endl;
      cin >> csuma;
      producto.stock = producto.stock + csuma;
      imprimirLinea();
    }
  }
}

void imprimirVentas() {
  for( Productoventa &productoventa: productosventas) {
    cout <<" Se vendió: "<< productoventa.producto << endl;
    cout <<" Nombre del comprador: "<< productoventa.nombreVenta << endl;
    cout <<" Cantidad de ventas: " << productoventa.nroproducto << endl;
    cout <<" Precio de venta: " << productoventa.precioVenta << endl;
    imprimirLinea();
  }
}
  
int main() {
  cout <<"|-------------------------------------------------|"<<endl;
  cout <<"|       BIENVENIDO AL SISTEMA DE INVENTARIO       |" << endl;
  cout <<"|-------------------------------------------------|"<<endl;
  inicioSesion();
  while(m != 8){
    switch(m) {
      case 1:
        flag = 1;
        while(flag == 1) {
          agregarProducto();
        }
        imprimirMenu();
        break;
      case 2:
        cout << " lISTA DE PRODUCTOS" << endl;
        buscarProducto();
        imprimirMenu();
        break;
      case 3:
        imprimirProductos();
        imprimirMenu();
        break;
      case 4:
        editarProducto();
        imprimirMenu();
        break;
      case 5:
        vender();
        imprimirMenu();
        break;
      case 6:
        comprarStock();
        imprimirMenu();
        break;
      case 7:
        imprimirVentas();
        imprimirMenu();
        break;
      default:
        cout << " OPCION INVALIDA" << endl;
    }
  }
  return 0;
}