#include "pch.h"

// ���������[�N�̃L���v�`��
#define _CRTDBG_MAP_ALLOC
#include <stdlib.h>
#include <crtdbg.h>

#include "CppUnitTest.h"
#include "../include/liblist.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest
{
	TEST_MODULE_CLEANUP(test_module_cleanup) {
		Assert::IsFalse(_CrtDumpMemoryLeaks());// ���������[�N�`�F�b�N
	}

	TEST_CLASS(UnitTest)
	{
	public:
		
		TEST_METHOD(front_added)
		{
			list l;
			add_front(&l, 1);
			Assert::AreEqual(1, l.head->data);

			delete_all(&l);
		}

		// �Ō�̃m�[�h��NULL
		TEST_METHOD(back_added)
		{
			list l;
			add_back(&l, 1);

			Assert::AreEqual(1, l.tail->data);

			delete_all(&l);
		}

		// �ŏ��̑O�m�[�h��NULL
		TEST_METHOD(next_get)
		{
			list l;
			add_front(&l, 1);
			add_back(&l, 2);

			Assert::AreEqual(2, get_next(l.head)->data);

			delete_all(&l);
		}

		// �ŏ��̑O�m�[�h��NULL
		TEST_METHOD(prev_get)
		{
			list l;
			add_front(&l, 1);
			add_back(&l, 2);

			Assert::AreEqual(1, get_prev(l.tail)->data);

			delete_all(&l);
		}


		// �ŏ��̑O�m�[�h��NULL
		TEST_METHOD(middle_node_depended)
		{
			list l;
			add_front(&l, 1);
			add_back(&l, 2);
			add_back(&l, 3);

			depend(get_prev(l.tail) , &l);// �^�񒆂̗v�f���폜

			node* p = l.head;
			Assert::AreEqual(1, p->data);
			p = p->next;
			Assert::AreEqual(3, p->data);
			p = p->next;
			Assert::IsNull(p);

			delete_all(&l);
		}

	};
}
