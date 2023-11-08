#pragma once
#include <gl/glew.h>

class IndexBuffer {
private:
	unsigned int m_rendererID;
	unsigned int m_count;
public:
	IndexBuffer(const unsigned int* data, unsigned int count);
	~IndexBuffer();
	void unbind()const;
	void bind() const;
	inline unsigned int getCount() { return m_count; }
};