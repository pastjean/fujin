#include "chinookpack/unpack.h"

typedef void unpack_user;

typedef  int (*callback_interface)(chinookpack_object*, const char* , size_t*);

static inline int callback_nil(chinookpack_object* o, const char* buf, size_t* off)
{ 
  o->type = CHINOOKPACK_OBJECT_NIL; return 0; 
}

static inline int callback_true(chinookpack_object* o, const char* buf, size_t* off)
{ 
  o->type = CHINOOKPACK_OBJECT_BOOLEAN; o->via.boolean = true; return 0; 
}

static inline int callback_false(chinookpack_object* o, const char* buf, size_t* off)
{ 
  o->type = CHINOOKPACK_OBJECT_BOOLEAN; o->via.boolean = false; return 0; 
}

static inline int callback_uint8(chinookpack_object* o, const char* buf, size_t* off)
{
  o->type = CHINOOKPACK_OBJECT_UINT8; 
  o->via.u64 = 0;
  o->via.u64 = buf[*off] & 0xff;
  (*off) +=1;
  return 0; 
}

static inline int callback_uint16(chinookpack_object* o, const char* buf, size_t* off)
{ 
  o->type = CHINOOKPACK_OBJECT_UINT16; 
  o->via.u64 = 0;
  o->via.u64 = (buf[*off]<<8) & 0xff00;
  o->via.u64 = (buf[*off+1]) & 0xff;
  (*off) +=2;
  return 0; 
}

static inline int callback_int8(chinookpack_object* o, const char* buf, size_t* off)
{ 
  o->type = CHINOOKPACK_OBJECT_INT8; 
  o->via.i64 = 0;
  o->via.i64 = buf[*off] & 0xff;
  (*off) +=1;
  return 0;
}

static inline int callback_int16(chinookpack_object* o, const char* buf, size_t* off)
{ 
  o->type = CHINOOKPACK_OBJECT_INT16; 
  o->via.i64 = 0;
  o->via.i64 = (buf[*off]<<8) & 0xff00;
  o->via.i64 = (buf[*off+1*sizeof(char)]) & 0xff;
  (*off) +=2;
  return 0; 
}

static inline int callback_float(chinookpack_object* o, const char* buf, size_t* off)
{ 
  union { float f; uint32_t i; } mem;
  mem.i = (((uint32_t)buf[*off] << 24) & 0xFF000000)
         |(((uint32_t)buf[*off+1*sizeof(char)] <<16) & 0x00FF0000)
         |(((uint32_t)buf[*off+2*sizeof(char)] << 8) & 0x0000FF00)
         |(((uint32_t)buf[*off+3*sizeof(char)]) & 0x000000FF);
    /*mem.i[0] = 1;
    mem.i[1] = 2;
    mem.i[2] = 3;
    mem.i[3] = 4;*/
  o->type = CHINOOKPACK_OBJECT_FLOAT; 
  o->via.dec = mem.f;
  (*off)+=4;
  return 0; 
}


bool chinookpack_unpack_next(chinookpack_unpacked* result,
		const char* buf, size_t len, size_t* off){
   char header = NULL;
  int i=0;
  callback_interface callback_pointer = NULL;

	size_t noff = 0;
	if(off != NULL) { noff = *off; }
  else { return false;}


	if(len <= noff) {
		return false;
	}
  

  // TODO: DO SHITS HERE
  // first : get the type header
  // second : make a big switch or something less good to see :) (gotos)
  //          or use a tool that would do it for you boy (ragel state machine compiler)
    header = *buf;
    noff+=1;
  // special raw case

  if( (0xa0 & header)  == 0xa0){
    //TODO: handle raw
    // callback raw
    // then finish
    goto ENDOF_CHINOOK_PACK_UNPACK_NEXT;
  }

  switch( (header & 0xff) ){
    case 0xc0:
      callback_pointer = callback_nil;
      break;
    case 0xc3:
      callback_pointer = callback_true;
      break;
    case 0xc2:
      callback_pointer = callback_false;
      break;
    case 0xcc:
      callback_pointer = callback_uint8;
      break;
    case 0xcd:
      callback_pointer = callback_uint16;
      break;
    case 0xd0:
      callback_pointer = callback_int8;
      break;
    case 0xd1:
      callback_pointer = callback_int16;
      break;
    case 0xca:
      callback_pointer = callback_float;
      break;
    default:
      // Unrecognised type
      return false;
  }
  
  if(callback_pointer != NULL){
    callback_pointer(&(result->data),buf,&noff);
  }


ENDOF_CHINOOK_PACK_UNPACK_NEXT:
	if(off != NULL) { *off = noff; }
  return true;
}
