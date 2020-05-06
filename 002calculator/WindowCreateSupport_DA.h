
//DA = Dynamic Array//

namespace WndCreateSupport {
	template<typename T>
	class WindowCreateSupport_DA
	{
	private:
		unsigned int stack_num = 0;
	public:
		WindowCreateSupport_DA(void);
		~WindowCreateSupport_DA(void);
		void operator()(T) {

		};
		void operator[](T) {

		};
		T at();
		void add();
		void erase();
		void destroy();

	};
};

