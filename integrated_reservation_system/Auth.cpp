#include "Auth.h"
#include "Console.h"

using namespace std;

template <typename User>
void Auth<User>::sign_up(vector<User>& user_data) {
	//���� �迭 users�� �����ڸ� ���ڷ� �޾Ƽ� �ű� ȸ�������� ����ϴ� �Լ�
	string userID;
	string userPW;
	User user = User();
	
	cout << "ȸ�������� �����մϴ�." << '\n';

	//Authentication begin

	while (1) {
		userID = Console::get_auth_id();
		if (user_auth_map.count(userID)) {
			cout << "�̹� �����ϴ� ���̵��Դϴ�." << '\n';
		}
		else {
			userPW = Console::get_auth_pw();
			break;
		}
	}

	user_auth_map[userID] = userPW; //user_auth_map�� ���̵�-��й�ȣ �� ���

	//Authentication end
	//Authorization begin
	
	user.set_name(Console::get_user_name());
	user.set_gender(Console::get_user_gender());
	user.set_age(Console::get_user_age());

	user_data->push_back(user); 
	//�ű� user ��ü�� �����Ͽ� �������ְ�, users ���Ϳ� push_back ����

	cout << "ȸ�������� ���������� �Ϸ�Ǿ����ϴ�." << '\n';
	//Authorization end
}

template <typename User>
pair<string, typename vector<User>::iterator> Auth<User>::sign_in() {
	string userID;
	string userPW;

	/*
	while (1) {
		userID = Console::get_auth_id();
		userPW = Console::get_auth_pw();

		auto it = Auth::user_auth_map.find(userID);
		if (it != user_auth_map.end()) {
			cout << "�α��ο� �����߽��ϴ�." << '\n';
			return userID;
		}
		else {
			cout << "�������� �ʴ� �����Դϴ�." << '\n';
		}
	}
	*/
}