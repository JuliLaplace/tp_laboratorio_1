#ifndef employee_H_INCLUDED
#define employee_H_INCLUDED
typedef struct
{
    int id;
    char nombre[128];
    int horasTrabajadas;
    int sueldo;
}Employee;


#endif // employee_H_INCLUDED

/** \brief Funcion que crea un nuevo campo de empleado en memoria y lo inicializa
 *
 * \return Employee* retorna la direccion de memoria donde guardo ese empleado.
 *
 */
Employee* employee_new();

/** \brief Funcion que crea un nuevo campo de empleado en memoria y lo carga con los datos (parametros) pasados
 *
 * \param idStr char* numero de id cargado como string
 * \param nombreStr char* nombre
 * \param horasTrabajadasStr char* horas trabajadas cargadas como string
 * \param sueldoStr char* sueldo cargado como string
 * \return Employee* retorna la direccion de memoria donde guardo ese empleado.
 *
 */
Employee* employee_newParametros(char* idStr,char* nombreStr,char* horasTrabajadasStr, char* sueldoStr);

/** \brief Funcion que elimina un empleado cargado
 *
 *\param this Employee* direccion de memoria de empleado que se eliminara
 * \return void
 *
 */
void employee_delete(Employee* this);

/** \brief Funcion que setea un ID en un empleado
 *
 * \param this Employee* direccion de memoria de empleado al que se le setea el ID
 * \param id int ID que se le setea
 * \return int retorna 1 si pudo setear el ID o 0 si no logro realizarlo
 *
 */
int employee_setId(Employee* this,int id);

/** \brief Funcion que obtiene un Id de un empleado
 *
 * \param this Employee* direcion de memoria del empleado
 * \param id int* direccion de memoria
 * \return int retorna 1 si logro obtener el ID del empleado o 0 si no pudo realizarlo
 *
 */
int employee_getId(Employee* this,int* id);

/** \brief Funcion que setea un nombre en un empleado
 *
 * \param this Employee* direcion de memoria del empleado
 * \param nombre char* nombre que se setea
 * \return int retorna 1 si pudo setear el nombre del empleado o 0 si no logro realizarlo
 *
 */
int employee_setNombre(Employee* this,char* nombre);

/** \brief
 *
 * \param this Employee* direcion de memoria del empleado
 * \param nombre char* direccion donde se guarda nombre
 * \return int retorna 1 si logro obtener el nombre del empleado o 0 si no pudo realizarlo
 *
 */
int employee_getNombre(Employee* this,char* nombre);

/** \brief Funcion que setea horas trabajadas en un empleado
 *
 * \param this Employee* direcion de memoria del empleado
 * \param horasTrabajadas int horas trabajadas a setear
 * \return int retorna 1 si pudo setear las horas trabajadas del empleado o 0 si no logro realizarlo
 *
 */
int employee_setHorasTrabajadas(Employee* this,int horasTrabajadas);

/** \brief
 *
 * \param this Employee* direcion de memoria del empleado
 * \param horasTrabajadas int* direccion de memoria donde se guardan las horas trabajadas
 * \return int retorna 1 si logro obtener las horas trabajadas del empleado o 0 si no pudo realizarlo
 *
 */
int employee_getHorasTrabajadas(Employee* this,int* horasTrabajadas);

/** \brief  Funcion que setea el sueldo en un empleado
 *
 * \param this Employee* direcion de memoria del empleado
 * \param sueldo float sueldo a setear
 * \return int retorna 1 si pudo setear el sueldo del empleado o 0 si no logro realizarlo
 *
 */
int employee_setSueldo(Employee* this,float sueldo);

/** \brief
 *
 * \param this Employee* direcion de memoria del empleado
 * \param sueldo float* direccion de memoria donde se va a guardar sueldo
 * \return int retorna 1 si logro obtener el sueldo del empleado o 0 si no pudo realizarlo
 *
 */
int employee_getSueldo(Employee* this,float* sueldo);

/** \brief Funcion que comprara el contenido de dos direcciones de memoria
 *
 * \param a void* primera direccion de memoria a la que se accede para comparar sus datos
 * \param b void* segunda direccion de memoria a la que se accede para comparar sus datos
 * \return int retorna 1 si pudo ordenar los empleados o 0 si no logro hacerlo
 *
 */

int employeeCmpNombre(void* a, void* b);
