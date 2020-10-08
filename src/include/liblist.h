#pragma once

// C++ ��C�̃��C�u�������g���Ƃ��̂��܂��Ȃ�
#ifdef __cplusplus
extern "C" {
#endif

	typedef struct node {
		int data;
		struct node* prev;
		struct node* next;
	}node;

	typedef struct list {
		struct node* head;
		struct node* tail;
	}list;


	// �擪��data�̒l�����m�[�h��ǉ�����
	void add_front(list* l, int data);

	// ������data�̒l�����m�[�h��ǉ�����
	void add_back(list* l, int data);
	
	// p�̌�̃m�[�h���擾����
	node* get_next(node* p);

	// p�̑O�̃m�[�h���擾����
	node* get_prev(node* p);

	// �m�[�h����菜���i����̓�����������s���j
	node* depend(node* p, list* l);

	// �g�p�������̑S���
	void delete_all(list* p);


// C++ ��C�̃��C�u�������g���Ƃ��̂��܂��Ȃ�
#ifdef __cplusplus
} // extern "C"
#endif