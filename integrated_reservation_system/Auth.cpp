#include <utility>
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
pair<string, User&> Auth<User>::sign_in(vector<User>& user_data) {
	string userID;
	string userPW;

	cout << "�α����� �����մϴ�." << '\n';

	//Authentication begin

	while (1) {
		userID = get_auth_id();
		userPW = get_auth_pw();
		auto it = user_auth_map.find(userID);
		if (it != user_auth_map.end()) {
			if (it->first == userID && it->second == userPW)
				break;
		}
		cout << "�Է��� ������ �������� �ʽ��ϴ�." << '\n';
	}

	//Authentication end
	//Authorization begin

	for (const auto& user : user_data) {//range-based loop. 'const auto&' for only read mode
		if (user.get_id() == userID)
			return make_pair(userID, user); //���̵�� users���� �ش� ���̵��� user ��ü ������ ��ȯ 
	}

	//Authorization end
}