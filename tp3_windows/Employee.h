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

/** \brief
 *
 * \return Employee*
 *
 */
Employee* employee_new();
/** \brief
 *
 * \param idStr char*
 * \param nombreStr char*
 * \param horasTrabajadasStr char*
 * \param sueldoStr char*
 * \return Employee*
 *
 */
Employee* employee_newParametros(char* idStr,char* nombreStr,char* horasTrabajadasStr, char* sueldoStr);
/** \brief
 *
 * \return this*
 *
 */
void employee_delete(Employee* this);
/** \brief
 *
 * \param this Employee*
 * \param id int
 * \return int
 *
 */
int employee_setId(Employee* this,int id);
/** \brief
 *
 * \param this Employee*
 * \param id int*
 * \return int
 *
 */
int employee_getId(Employee* this,int* id);
/** \brief
 *
 * \param this Employee*
 * \param nombre char*
 * \return int
 *
 */
int employee_setNombre(Employee* this,char* nombre);
/** \brief
 *
 * \param this Employee*
 * \param nombre char*
 * \return int
 *
 */
int employee_getNombre(Employee* this,char* nombre);
/** \brief
 *
 * \param this Employee*
 * \param horasTrabajadas int
 * \return int
 *
 */
int employee_setHorasTrabajadas(Employee* this,int horasTrabajadas);
/** \brief
 *
 * \param this Employee*
 * \param horasTrabajadas int*
 * \return int
 *
 */
int employee_getHorasTrabajadas(Employee* this,int* horasTrabajadas);
/** \brief
 *
 * \param this Employee*
 * \param sueldo float
 * \return int
 *
 */
int employee_setSueldo(Employee* this,float sueldo);
/** \brief
 *
 * \param this Employee*
 * \param sueldo float*
 * \return int
 *
 */
int employee_getSueldo(Employee* this,float* sueldo);
/** \brief
 *
 * \param a void*
 * \param b void*
 * \return int
 *
 */
int employeeCmpHoras(void* a, void* b);
/** \brief
 *
 * \param a void*
 * \param b void*
 * \return int
 *
 */
int employeeCmpSueldo(void* a, void* b);
/** \brief
 *
 * \param a void*
 * \param b void*
 * \return int
 *
 */
int employeeCmpNombre(void* a, void* b);
